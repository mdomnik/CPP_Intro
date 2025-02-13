/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:32 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 00:43:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include <iostream>

int main()
{
	//Default Polymorthism test
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

	//default Wrong Polymorthism implementation test
	{
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

	// Copy and Assignment test
	{
		std::cout << "\033[1;35m\n=== Copy and Assignment ===\033[0m" << std::endl;

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
	std::cout << "\033[1;35m=== Copy and Assignment Tests Concluded ===\033[0m\n" << std::endl;

	//Polymorthism Memory Test
	{
		#define ANIMAL_AMOUNT 8

		std::cout << "\033[1;35m\n=== Polymorthism Memory Test ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Creating Animal Array ===\033[0m" << std::endl;
		Animal* animals[ANIMAL_AMOUNT];

		for (int i = 0; i < ANIMAL_AMOUNT / 2; i++)
			animals[i] = new Dog();
		for (int i = ANIMAL_AMOUNT / 2; i < ANIMAL_AMOUNT; i++)
			animals[i] = new Cat();

		std::cout << "\033[1;34m=== Making Sounds ===\033[0m" << std::endl;
		for (int i = 0; i < ANIMAL_AMOUNT; i++)
			animals[i]->makeSound();

		std::cout << "\033[1;31m=== Deleting Animals ===\033[0m" << std::endl;
		for (int i = 0; i < ANIMAL_AMOUNT; i++)
			delete animals[i];

		std::cout << "\033[1;35m=== Polymorthism Memory Test Concluded ===\033[0m\n" << std::endl;
	}

	//Deep Copy Test
	{
		std::cout << "\033[1;35m\n=== Deep Copy Test ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Creating oldDog ===\033[0m" << std::endl;
		Dog oldDog;
		oldDog.setIdea(0, "I love my human!");

		std::cout << "\033[1;32m=== Copying Dog ===\033[0m" << std::endl;
		Dog copiedDog(oldDog);

		std::cout << "oldDog Idea (pre change): " << oldDog.getIdea(0) << std::endl;
		std::cout << "copiedDog Idea (pre change): " << copiedDog.getIdea(0) << std::endl;

		copiedDog.setIdea(0, "I hate my human!!!");

		std::cout << "oldDog Idea (post change): " << oldDog.getIdea(0) << std::endl;
		std::cout << "copiedDog Idea (post change): " << copiedDog.getIdea(0) << std::endl;
		std::cout << "\033[1;31m=== Destructors Called ===\033[0m" << std::endl;
	}
	std::cout << "\033[1;35m=== Deep Copy Test Concluded ===\033[0m\n" << std::endl;

	std::cout << "\033[1;35m=== All Tests Concluded ===\033[0m\n" << std::endl;
	return 0;
}

