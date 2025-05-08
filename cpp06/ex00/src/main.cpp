/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:05:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/08 20:48:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <iostream>

void testLiteral(const std::string& input)
{
	std::cout << "\033[1;36mTesting input: \"" << input << "\"\033[0m" << std::endl;
	ScalarConverter::convert(input);
	std::cout << "\033[1;34m---\033[0m" << std::endl;
}

void testCases(void)
{
	std::cout << "\033[1;35m=== ScalarConverter Test Suite ===\033[0m\n" << std::endl;

	// CHAR tests
	{
		std::cout << "\033[1;35m--- CHAR Tests ---\033[0m" << std::endl;
		testLiteral("a");
		testLiteral("Z");
		testLiteral("~");
		testLiteral("1");  // valid int, not char
		testLiteral("\t"); // tab, non-displayable
	}

	// INT tests
	{
		std::cout << "\033[1;35m--- INT Tests ---\033[0m" << std::endl;
		testLiteral("0");
		testLiteral("42");
		testLiteral("-1337");
		testLiteral("2147483647");  // INT_MAX
		testLiteral("-2147483648"); // INT_MIN
		testLiteral("2147483648");  // overflow
		testLiteral("abc123");      // invalid
	}

	// FLOAT tests
	{
		std::cout << "\033[1;35m--- FLOAT Tests ---\033[0m" << std::endl;
		testLiteral("42.0f");
		testLiteral("-0.001f");
		testLiteral("123456.789f");
		testLiteral("3.14ff"); // wrong
		testLiteral("12.34f56"); // wrong
	}

	// DOUBLE tests
	{
		std::cout << "\033[1;35m--- DOUBLE Tests ---\033[0m" << std::endl;
		testLiteral("42.0");
		testLiteral("-0.001");
		testLiteral("123456.789");
		testLiteral("3.14.15"); // invalid
	}

	// PSEUDO-LITERAL tests
	{
		std::cout << "\033[1;35m--- PSEUDO-LITERAL Tests ---\033[0m" << std::endl;
		testLiteral("nan");
		testLiteral("nanf");
		testLiteral("+inf");
		testLiteral("+inff");
		testLiteral("-inf");
		testLiteral("-inff");
	}

	// UNKNOWN tests
	{
		std::cout << "\033[1;35m--- UNKNOWN/INVALID Tests ---\033[0m" << std::endl;
		testLiteral("hello22");
		testLiteral("++42");
		testLiteral(""); //empty
		testLiteral(" "); //char
		testLiteral("f"); //char
		testLiteral(".."); //wrong
	}

	std::cout << "\033[1;32m=== ScalarConverter Test Suite Concluded ===\033[0m\n" << std::endl;
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}

	if (std::string(argv[1]) == "test")
	{
		std::cout << "\033[1;33mRunning test suite...\033[0m" << std::endl;
		testCases();
		return (0);
	}
	else
		ScalarConverter::convert(argv[1]);
	return (0);
}
