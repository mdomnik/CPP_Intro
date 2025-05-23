/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:58:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/23 16:35:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define TEST_CASE(name) std::cout << "\n\033[1;34m=== " << name << " ===\033[0m\n";

int main() {
	std::srand(std::time(0));

	// Given example
	{
		TEST_CASE("Basic Span Functionality");
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should be 2
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Should be 14
		std::cout << "\033[1;34m----------------------------------\033[0m\n" << std::endl;
	}

	// Overflow Check
	{
		TEST_CASE("Overflow Exception");
		Span sp(2);
		try {
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3); // Should throw
		} catch (const std::exception& e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
		std::cout << "\033[1;34m----------------------------\033[0m\n" << std::endl;
	}

	// Span With Insufficient Elements
	{
		TEST_CASE("Span Exception Handling");
		Span sp(1);
		sp.addNumber(42);
		try {
			sp.shortestSpan(); // Should throw
		} catch (const std::exception& e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
		try {
			sp.longestSpan(); // Should also throw
		} catch (const std::exception& e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
		std::cout << "\033[1;34m-------------------------------\033[0m\n" << std::endl;
	}

	// Large Random Dataset
	{
		TEST_CASE("Large Dataset (10,000+)");
		Span sp(10005);

		// Add some manual numbers
		sp.addNumber(1);
		sp.addNumber(50000);
		sp.addNumber(100000);
		sp.addNumber(-100);
		sp.addNumber(0);

		// Fill with 10,000 random numbers
		std::vector<int> numbers;
		for (int i = 0; i < 10000; ++i)
			numbers.push_back(std::rand());

		sp.addMany(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "\033[1;34m----------------------------------\033[0m\n" << std::endl;
	}

	// Duplicate Numbers
	{
		TEST_CASE("Span with Duplicates");
		Span sp(3);
		sp.addNumber(100);
		sp.addNumber(100);
		sp.addNumber(100);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should be 0
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Should be 0
		std::cout << "\033[1;34m------------------------------\033[0m\n" << std::endl;
	}

	std::cout << "\033[1;32m=== All Tests Completed ===\033[0m" << std::endl;
	return (0);
}
