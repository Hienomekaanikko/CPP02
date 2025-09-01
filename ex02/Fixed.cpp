/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:22:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/16 15:18:19 by msuokas          ###   ########.fr       */
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
	//std::cout << "Int constructor called" << std::endl;
	fixed_point_nbr = n << fract_bits;
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" << std::endl;
	fixed_point_nbr = roundf(f * (1 << fract_bits));
}

Fixed::Fixed() : fixed_point_nbr(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	fixed_point_nbr = other.fixed_point_nbr;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point_nbr = other.fixed_point_nbr;
	return *this;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	long long temp = (long long)this->fixed_point_nbr * other.fixed_point_nbr;
	result.fixed_point_nbr = (int)(temp >> fract_bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	long long temp = ((long long)this->fixed_point_nbr << fract_bits) / other.fixed_point_nbr;
	result.fixed_point_nbr = (int)temp;
	return result;
}


Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result.fixed_point_nbr = this->fixed_point_nbr + other.fixed_point_nbr;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result.fixed_point_nbr = this->fixed_point_nbr - other.fixed_point_nbr;
	return result;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->fixed_point_nbr > other.fixed_point_nbr;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->fixed_point_nbr < other.fixed_point_nbr;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->fixed_point_nbr >= other.fixed_point_nbr;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->fixed_point_nbr <= other.fixed_point_nbr;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->fixed_point_nbr == other.fixed_point_nbr;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->fixed_point_nbr != other.fixed_point_nbr;
}

Fixed& Fixed::operator++()
{
	this->fixed_point_nbr++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixed_point_nbr++;
	return temp;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}


const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}
