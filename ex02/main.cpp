/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:22:42 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/02 16:07:03 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
	//std::cout << "Constructor tests: \n";
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	//std::cout << "Assignment test: \n";
	a = Fixed(123.456f);

	std::cout << "Values to test with: \n";
	std::cout << "a: " << a << "\n";
	std::cout << "b: " << b << "\n";
	std::cout << "c: " << c << "\n";
	std::cout << "d: " << d << "\n";
	std::cout << "-----------------------\n\n";
	std::cout << "Arithmetic operations: \n";
	Fixed sum = b + c;
	Fixed sum_of_three = b + b + b;
	Fixed diff = c - b;
	Fixed prod = b * c;
	Fixed quot = c / b;

	std::cout << "b + c = " << sum << "\n";
	std::cout << "b + b + b = " << sum_of_three << "\n";

	std::cout << "c - b = " << diff << "\n";
	std::cout << "b * c = " << prod << "\n";
	std::cout << "c / b = " << quot << "\n";
	std::cout << "-----------------------\n\n";
	std::cout << "Comparisons:\n";

	std::cout << "b > c: " << (b > c) << "\n";
	std::cout << "b < c: " << (b < c) << "\n";
	std::cout << "b >= d: " << (b >= d) << "\n";
	std::cout << "b <= d: " << (b <= d) << "\n";
	std::cout << "b == d: " << (b == d) << "\n";
	std::cout << "b != c: " << (b != c) << "\n";
	std::cout << "-----------------------\n\n";

	std::cout << "Increments:\n";
	Fixed e;
	std::cout << "e: " << e << "\n";
	std::cout << "++e: " << ++e << "\n";
	std::cout << "e++: " << e++ << "\n";
	std::cout << "e after e++: " << e << "\n";
	std::cout << "-----------------------\n\n";

	std::cout << "Decrements:\n";
	Fixed z;
	std::cout << "z: " << z << "\n";
	std::cout << "--z: " << --z << "\n";
	std::cout << "z--: " << z-- << "\n";
	std::cout << "z after z--: " << z << "\n";
	std::cout << "-----------------------\n\n";

	std::cout << "Max:\n";
	Fixed low(7.7f);
	Fixed high(3.3f);
	std::cout << "low = 3.3, high = 7.7: " << std::endl;
	std::cout << "Max of 'low' and 'high': " << Fixed::max(low, high) << "\n";
	std::cout << "Max of const 'low' and 'high': " << Fixed::max(static_cast<const Fixed&>(low), static_cast<const Fixed&>(high)) << "\n\n";

	std::cout << "Min:\n";
	Fixed low2(1);
	Fixed high2(10);
	std::cout << "low = 1, high = 10: " << std::endl;
	std::cout << "Min of 'low' and 'high' " << Fixed::min(low2, high2) << "\n";
	std::cout << "Min of const 'low' and const 'high' " << Fixed::min(static_cast<const Fixed&>(low2), static_cast<const Fixed&>(high2)) << "\n";

	std::cout << "-----------------------\n\n";
	std::cout << "From fixed point to int conversion:\n";
	std::cout << "a as int: " << a.toInt() << "\n";
	std::cout << "c as int: " << c.toInt() << "\n";

	std::cout << "-----------------------\n\n";


	return 0;
}
