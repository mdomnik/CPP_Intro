/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:05:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 22:58:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << "\033[1;35m=== Template Function Tests ===\033[0m\n" << std::endl;

	// 🔹 Given test case
	{
		std::cout << "\033[1;33m--- INT + STRING TEST (Given Example) ---\033[0m" << std::endl;
		int a = 2;
		int b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl; // a = 3, b = 2
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl; // 2
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl; // 3

		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl; // chaine2, chaine1
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl; // chaine1
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl; // chaine2
		std::cout << "\033[1;34m----------------------\033[0m\n" << std::endl;
	}

	// 🔹 Float test
	{
		std::cout << "\033[1;33m--- FLOAT TEST ---\033[0m" << std::endl;
		float x = 42.5f;
		float y = 13.37f;
		::swap(x, y);
		std::cout << "x = " << x << ", y = " << y << std::endl;
		std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
		std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
		std::cout << "\033[1;34m----------------------\033[0m\n" << std::endl;
	}

	// 🔹 Char test
	{
		std::cout << "\033[1;33m--- CHAR TEST ---\033[0m" << std::endl;
		char c1 = 'z';
		char c2 = 'a';
		::swap(c1, c2);
		std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
		std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
		std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;
		std::cout << "\033[1;34m----------------------\033[0m\n" << std::endl;
	}

	// 🔹 Bool test
	{
		std::cout << "\033[1;33m--- BOOL TEST ---\033[0m" << std::endl;
		bool p = true;
		bool q = false;
		::swap(p, q);
		std::cout << std::boolalpha;
		std::cout << "p = " << p << ", q = " << q << std::endl;
		std::cout << "min(p, q) = " << ::min(p, q) << std::endl;
		std::cout << "max(p, q) = " << ::max(p, q) << std::endl;
		std::cout << "\033[1;34m----------------------\033[0m\n" << std::endl;
	}

		// 🔹 Equal Int Test: second value must be returned
	{
		std::cout << "\033[1;33m--- EQUAL INTEGERS TEST ---\033[0m" << std::endl;
	
		int a = 100;
		int b = 100;
	
		std::cout << "Addresses: &a = " << &a << ", &b = " << &b << std::endl;
	
		const int& minResult = ::min(a, b);
		const int& maxResult = ::max(a, b);
	
		std::cout << "min(a, b) = " << minResult << " (from " << ((&minResult == &b) ? "b" : "a") << ")" << std::endl;
		std::cout << "max(a, b) = " << maxResult << " (from " << ((&maxResult == &b) ? "b" : "a") << ")" << std::endl;
	
		std::cout << "\033[1;34m----------------------\033[0m\n" << std::endl;
	}


	std::cout << "\033[1;32m=== All Tests Complete ===\033[0m" << std::endl;
	return 0;
}
