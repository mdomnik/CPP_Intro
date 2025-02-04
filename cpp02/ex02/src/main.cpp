/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/04 17:44:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main( void )
{
	Fixed x;
	Fixed const y( Fixed(5.05f) * Fixed(2));
	
	std::cout << "=== Subject Tests ===" << std::endl;
	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << Fixed::max(x,y) << std::endl;

	std::cout << "=== Constructors and Assignment ===" << std::endl;
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	a = Fixed(1234.4321f);

	std::cout << "\nValues:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	std::cout << "\n=== Arithmetic Operators ===" << std::endl;
	Fixed add = b + c;
	Fixed sub = c - b;
	Fixed mul = b * c;
	Fixed div = c / b;
	std::cout << "b + c = " << add << std::endl;
	std::cout << "c - b = " << sub << std::endl;
	std::cout << "b * c = " << mul << std::endl;
	std::cout << "c / b = " << div << std::endl;

	std::cout << "\n=== Comparison Operators ===" << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= d: " << (b >= d) << std::endl;
	std::cout << "b <= d: " << (b <= d) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << "\n=== Increment/Decrement Operators ===" << std::endl;
	Fixed e;
	std::cout << "Initial e: " << e << std::endl;
	std::cout << "Pre-increment ++e: " << ++e << std::endl; //smallest step being 1/256
	std::cout << "Post-increment e++: " << e++ << std::endl;
	std::cout << "After post-increment, e: " << e << std::endl;
	std::cout << "Pre-decrement --e: " << --e << std::endl;
	std::cout << "Post-decrement e--: " << e-- << std::endl;
	std::cout << "After post-decrement, e: " << e << std::endl;

	std::cout << "\n=== Static min/max Functions ===" << std::endl;
	Fixed &minFixed	  = Fixed::min(b, c);
	const Fixed &minConst = Fixed::min(static_cast<const Fixed&>(b), static_cast<const Fixed&>(c));
	Fixed &maxFixed	  = Fixed::max(b, c);
	const Fixed &maxConst = Fixed::max(static_cast<const Fixed&>(b), static_cast<const Fixed&>(c));

	std::cout << "min(b, c): " << minFixed << std::endl;
	std::cout << "min(const b, c): " << minConst << std::endl;
	std::cout << "max(b, c): " << maxFixed << std::endl;
	std::cout << "max(const b, c): " << maxConst << std::endl;

	std::cout << "\n=== Div by 0 ===" << std::endl;
	Fixed num(5);
	Fixed zero(0);
	Fixed division = num / zero;
	std::cout << division << std::endl;
	return 0;
}