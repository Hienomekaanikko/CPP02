/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:19:51 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/16 14:06:03 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

float Fixed::toFloat(void) const
{
	return (float)fixed_point_nbr / (1 << fract_bits);
}

int Fixed::toInt(void) const
{
	return fixed_point_nbr >> fract_bits;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_nbr = n << fract_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_nbr = roundf(f * (1 << fract_bits));
}

Fixed::Fixed() : fixed_point_nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point_nbr = other.fixed_point_nbr;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point_nbr = other.fixed_point_nbr;
	return *this;
}
