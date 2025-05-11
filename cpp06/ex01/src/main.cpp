/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:41:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/09 00:48:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialize.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[1;35m=== Serializer Test ===\033[0m" << std::endl;

	// Create a data pointer
	std::cout << "\n\033[1;33m--- Step 1: Create Data ---\033[0m" << std::endl;
	Data original;
	original.name = "John Doe";
	original.age = 42;

	std::cout << "Original pointer: " << &original << std::endl;
	std::cout << "Original data: [age: " << original.age << ", name: \"" << original.name << "\"]" << std::endl;

	// Step 2: Serialize the pointer
	std::cout << "\n\033[1;33m--- Step 2: Serialize Data ---\033[0m" << std::endl;
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	// Step 3: Deserialize it back to a pointer
	std::cout << "\n\033[1;33m--- Step 3: Deserialize Data ---\033[0m" << std::endl;
	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored pointer: " << restored << std::endl;

	// Step 4: Compare and verify
	std::cout << "\n\033[1;33m--- Result ---\033[0m" << std::endl;
	if (restored == &original)
	{
		std::cout << "Pointers match!" << std::endl;
		std::cout << "Restored data: [age: " << restored->age << ", name: \"" << restored->name << "\"]" << std::endl;
	}
	else
		std::cout << "Pointers do not match!" << std::endl;

	std::cout << "\n\033[1;32m=== Serializer Test Concluded ===\033[0m\n" << std::endl;
	return (0);
}