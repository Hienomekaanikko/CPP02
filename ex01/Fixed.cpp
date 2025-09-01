#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed(): fixed_point_value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	fixed_point_value = n << fract_bits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(n * (1 << fract_bits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point_value = other.fixed_point_value;
	return *this;
}

float Fixed::toFloat( void ) const {
	return (float)fixed_point_value / (1 << fract_bits);
}

int Fixed::toInt( void ) const {
	return fixed_point_value >> fract_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
