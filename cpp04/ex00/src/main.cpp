/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:32 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:10:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "\033[1;35m=== Default Test ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Constructors ===\033[0m" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\033[1;34m=== Checking Types ===\033[0m" << std::endl;
		std::cout << "Expected: Dog, Actual: "<< j->getType() << std::endl;
		std::cout << "Expected: Cat, Actual: "<< i->getType() << std::endl;
		std::cout << "Expected: Animal, Actual: " << meta->getType() << std::endl;
		std::cout << "\033[1;34m=== Making Sounds ===\033[0m" << std::endl;
		std::cout << "Dog Says: ";
		j->makeSound();
		std::cout << "Cat Says: ";
		i->makeSound();
		std::cout << "Animal Says: ";
		meta->makeSound();

		std::cout << "\033[1;31m=== Destructors Called ===\033[0m" << std::endl;
		delete meta;
		delete j;
		delete i;

		std::cout << "\033[1;35m=== Test Concluded ===\033[0m" << std::endl;
	}

	{
		// Test with WrongAnimal and WrongCat (Demonstrating the Polymorphism Issue)
		std::cout << "\033[1;35m\n=== WrongAnimal Test ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Constructors ===\033[0m" << std::endl;
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		const WrongCat* actualWrongCat = new WrongCat();

		std::cout << "\033[1;34m=== Checking Types ===\033[0m" << std::endl;
		std::cout << "Expected: WrongAnimal, Actual: "<< wrongMeta->getType() << std::endl;
		std::cout << "Expected: WrongCat, Actual: "<< wrongCat->getType() << std::endl;
		std::cout << "Expected: WrongCat, Actual: "<< actualWrongCat->getType() << std::endl;

		std::cout << "\033[1;34m=== Making Sounds ===\033[0m" << std::endl;
		std::cout << "WrongAnimal Says: ";
		wrongMeta->makeSound(); // Expected: "Random WrongAnimal sound!"
		std::cout << "WrongCat (Stored as WrongAnimal*) Says: ";
		wrongCat->makeSound(); // Expected: "Random WrongAnimal sound!" (Polymorphism is broken)
		std::cout << "WrongCat (Stored as WrongCat*) Says: ";
		actualWrongCat->makeSound(); // Expected: "WrongMeow (WrongCat sound)" (Direct call works)

		std::cout << "\033[1;31m=== Destructors Called ===\033[0m" << std::endl;
		delete wrongMeta;
		delete wrongCat;
		delete actualWrongCat;

		std::cout << "\033[1;35m=== WrongAnimal Test Concluded ===\033[0m\n" << std::endl;
	}
	{
		// Extra Tests for Copy Constructor and Assignment Operator
		std::cout << "\033[1;35m\n=== Extra Tests: Copy and Assignment ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Creating Original Objects ===\033[0m" << std::endl;
		Dog originalDog;
		Cat originalCat;
		WrongCat originalWrongCat;

		std::cout << "\033[1;32m=== Copy Construction ===\033[0m" << std::endl;
		Dog copiedDog(originalDog);
		Cat copiedCat(originalCat);
		WrongCat copiedWrongCat(originalWrongCat);

		std::cout << "\033[1;32m=== Assignment Operator ===\033[0m" << std::endl;
		Dog assignedDog;
		assignedDog = copiedDog;
		Cat assignedCat;
		assignedCat = copiedCat;
		WrongCat assignedWrongCat;
		assignedWrongCat = copiedWrongCat;
		std::cout << "\033[1;31m=== Destructors ===\033[0m" << std::endl;
	}
	std::cout << "\033[1;35m=== Extra Tests Concluded ===\033[0m\n" << std::endl;
	return 0;
}

// int main()
// {
// 	std::cout << "### Testing Correct Classes ###" << std::endl;
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << "\nTesting makeSound() with correct classes..." << std::endl;
// 	j->makeSound();
// 	i->makeSound();

// 	std::cout << "\nDestroying Correct Animals..." << std::endl;
// 	delete j;
// 	delete i;

// 	// Testing WrongAnimal and WrongCat
// 	std::cout << "\n### Testing WrongAnimal and WrongCat ###" << std::endl;
// 	const WrongAnimal* meta = new WrongAnimal();
// 	const WrongAnimal* wrongCat = new WrongCat();
// 	const WrongCat* actualWrongCat = new WrongCat();

// 	std::cout << "\nTesting makeSound() with wrong classes..." << std::endl;
// 	meta->makeSound(); // Should print "Some generic wrong animal sound!"
// 	wrongCat->makeSound(); // Should print "Some generic wrong animal sound!" because it's not virtual!
// 	actualWrongCat->makeSound(); // Should print "Meow? (WrongCat sound)" because it's called on WrongCat directly.

// 	std::cout << "\nDestroying Wrong Animals..." << std::endl;
// 	delete meta;
// 	delete wrongCat;
// 	delete actualWrongCat;

// 	return 0;
// }
