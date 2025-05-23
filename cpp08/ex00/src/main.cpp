/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:41:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/13 01:49:39 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define TEST_CASE(name) std::cout << "\n\033[1;34m=== " << name << " ===\033[0m\n";

int main()
{
	{
		TEST_CASE("Testing std::vector<int>")
		std::vector<int> vec;
		for (int i = 1; i <= 5; ++i)
			vec.push_back(i * 10);
		
		try {
			std::cout << "Looking for 30... ";
			int index = easyfind(vec, 30);
			std::cout << "Found at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	
		try {
			std::cout << "Looking for 99... ";
			int index = easyfind(vec, 99);
			std::cout << "Found at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}
	{
		TEST_CASE("Testing std::list<int>")
		std::list<int> lst;
		for (int i = 0; i < 5; ++i)
			lst.push_back(i + 100);
		
		try {
			std::cout << "Looking for 102... ";
			int index = easyfind(lst, 102);
			std::cout << "Found at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	
		try {
			std::cout << "Looking for 42... ";
			int index = easyfind(lst, 42);
			std::cout << "Found at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}
	{
		TEST_CASE("Testing std::deque<int>")
		std::deque<int> deq;
		for (int i = 0; i < 4; ++i)
			deq.push_back(i * 5);
		
		try {
			std::cout << "Looking for 10... ";
			int index = easyfind(deq, 10);
			std::cout << "Found at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	
		try {
			std::cout << "Looking for -1... ";
			int index = easyfind(deq, -1);
			std::cout << "Found at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}
	return 0;
}
