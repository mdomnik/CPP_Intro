/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:57:52 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 23:40:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <iostream>
#include <string>


void printInt(int x) {
	std::cout << "int: " << x << std::endl;
}

void printChar(char c) {
	std::cout << "char: '" << c << "'" << std::endl;
}

void printString(const std::string& s) {
	std::cout << "string: \"" << s << "\"" << std::endl;
}

void square(int &x) {
	x *= x;
}

struct Point {
	int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

void printPoint(const Point& p) {
	std::cout << "Point: " << p << std::endl;
}

int main()
{
	std::cout << "\033[1;35m=== iter() Template Tests ===\033[0m\n" << std::endl;

	// ─────────── INT TEST ───────────
	{
		std::cout << "\033[1;33m--- INT ARRAY ---\033[0m" << std::endl;
		int nums[] = {1, 2, 3, 4, 5};
		iter(nums, 5, printInt);
		std::cout << "\033[1;34m-----------------\033[0m\n" << std::endl;
	}

	// ─────────── STRING TEST ───────────
	{
		std::cout << "\033[1;33m--- STRING ARRAY ---\033[0m" << std::endl;
		std::string strs[] = {"apple", "banana", "cherry"};
		iter(strs, 3, printString);
		std::cout << "\033[1;34m--------------------\033[0m\n" << std::endl;
	}

	// ─────────── CHAR TEST ───────────
	{
		std::cout << "\033[1;33m--- CHAR ARRAY ---\033[0m" << std::endl;
		char letters[] = {'A', 'B', 'C', 'D'};
		iter(letters, 4, printChar);
		std::cout << "\033[1;34m------------------\033[0m\n" << std::endl;
	}

	// ─────────── CUSTOM STRUCT TEST ───────────
	{
		std::cout << "\033[1;33m--- CUSTOM STRUCT ARRAY ---\033[0m" << std::endl;
		Point points[] = {{1, 2}, {3, 4}, {5, 6}};
		::iter(points, 3, printPoint);
		std::cout << "\033[1;34m---------------------------\033[0m\n" << std::endl;
	}

	// ─────────── IN-PLACE MODIFICATION TEST ───────────
	{
		std::cout << "\033[1;33m--- IN-PLACE SQUARE ---\033[0m" << std::endl;
		int numbers[] = {1, 2, 3, 4};
		::iter(numbers, 4, square);
		::iter(numbers, 4, printInt);
		std::cout << "\033[1;34m------------------------\033[0m\n" << std::endl;
	}

	std::cout << "\033[1;32m=== All iter() Tests Complete ===\033[0m" << std::endl;
	return 0;
}
