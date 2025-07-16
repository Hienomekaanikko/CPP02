/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:56:34 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/16 13:18:33 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixed_point_nbr;
		static const int	fract_bits = 8;
	public:
		//constructor
		Fixed();
		//copy constructor
		Fixed(const Fixed& other);
		//copy assignment operator
		Fixed& operator=(const Fixed& other);
		//destructor
		~Fixed();
		//member functions
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
