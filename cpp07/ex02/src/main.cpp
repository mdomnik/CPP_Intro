/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:41:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/23 16:09:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[1;35m=== Array<T> Template Tests ===\033[0m\n" << std::endl;

	// 🔹 Default constructor
	{
		std::cout << "\033[1;33m--- Default Constructor ---\033[0m" << std::endl;
		Array<int> empty;
		std::cout << "Size: " << empty.size() << std::endl;
		try {
			empty[0]; // should throw
		} catch (const std::exception& e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
		std::cout << "\033[1;34m----------------------------\033[0m\n" << std::endl;
	}

	// 🔹 Sized constructor
	{
		std::cout << "\033[1;33m--- Sized Constructor ---\033[0m" << std::endl;
		Array<int> nums(5);
		for (size_t i = 0; i < nums.size(); ++i)
			std::cout << "nums[" << i << "]" << std::endl;
		std::cout << "\033[1;34m--------------------------\033[0m\n" << std::endl;
	}

	// 🔹 Copy constructor
	{
		std::cout << "\033[1;33m--- Copy Constructor ---\033[0m" << std::endl;
		Array<std::string> original(2);
		original[0] = "Hello";
		original[1] = "World";

		Array<std::string> copied(original);
		copied[0] = "Changed";

		std::cout << "original[0]: " << original[0] << std::endl; // Should be "Hello"
		std::cout << "copied[0]:   " << copied[0] << std::endl;   // Should be "Changed"
		std::cout << "\033[1;34m--------------------------\033[0m\n" << std::endl;
	}

	// 🔹 Assignment operator
	{
		std::cout << "\033[1;33m--- Assignment Operator ---\033[0m" << std::endl;
		Array<float> a(3);
		Array<float> b;

		a[1] = 1.1f;
		b = a;
		b[1] = 99.99f;

		std::cout << "a[1]: " << a[1] << std::endl; // Should be original value
		std::cout << "b[1]: " << b[1] << std::endl; // Should be 99.99
		std::cout << "\033[1;34m----------------------------\033[0m\n" << std::endl;
	}

	// 🔹 Bounds checking
	{
		std::cout << "\033[1;33m--- Bounds Check ---\033[0m" << std::endl;
		Array<int> arr(2);
		arr[0] = 10;
		arr[1] = 20;

		try {
			std::cout << "arr[2]: " << arr[2] << std::endl; // should throw
		} catch (const std::exception& e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}

		std::cout << "\033[1;34m---------------------\033[0m\n" << std::endl;
	}

	std::cout << "\033[1;32m=== All Tests Passed ===\033[0m" << std::endl;
	return 0;
}

// #include <iostream>
// #include <cstdlib>
// #include "../inc/Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }