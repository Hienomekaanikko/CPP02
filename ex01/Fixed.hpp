#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	fixed_point_value;
		static const int fract_bits;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		~Fixed();

		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
