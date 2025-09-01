/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:22:42 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/16 14:44:51 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
	std::cout << "constructor tests: \n";
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	std::cout << "assignment test: \n";
	a = Fixed(123.456f);

	std::cout << "values: \n";
	std::cout << "a: " << a << "\n";
	std::cout << "b: " << b << "\n";
	std::cout << "c: " << c << "\n";
	std::cout << "d: " << d << "\n";
	std::cout << "-----------------------\n";
	std::cout << "arithmetic operations: \n";
	Fixed sum = b + c;
	Fixed diff = c - b;
	Fixed prod = b * c;
	Fixed quot = c / b;

	std::cout << "b + c = " << sum << "\n";
	std::cout << "c - b = " << diff << "\n";
	std::cout << "b * c = " << prod << "\n";
	std::cout << "c / b = " << quot << "\n";
	std::cout << "-----------------------\n";
	std::cout << "comparisons:\n";
	std::cout << "b > c: " << (b > c) << "\n";
	std::cout << "b < c: " << (b < c) << "\n";
	std::cout << "b >= d: " << (b >= d) << "\n";
	std::cout << "b <= d: " << (b <= d) << "\n";
	std::cout << "b == d: " << (b == d) << "\n";
	std::cout << "b != c: " << (b != c) << "\n";
	std::cout << "-----------------------\n";
	std::cout << "increments:\n";
	Fixed e;
	std::cout << "e: " << e << "\n";
	std::cout << "++e: " << ++e << "\n";
	std::cout << "e++: " << e++ << "\n";
	std::cout << "e after e++: " << e << "\n";
	std::cout << "-----------------------\n";
	std::cout << "max:\n";
	Fixed f(7.7f);
	Fixed g(3.3f);
	std::cout << "Max of f and g: " << Fixed::max(f, g) << "\n";
	std::cout << "Max of const f and g: " << Fixed::max(static_cast<const Fixed&>(f), static_cast<const Fixed&>(g)) << "\n";

	std::cout << "-----------------------\n";
	std::cout << "int conversion:\n";
	std::cout << "a as int: " << a.toInt() << "\n";
	std::cout << "c as int: " << c.toInt() << "\n";

	return 0;
}

