/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:32 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/06 17:47:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>

void testAnimal()
{
	std::cout << "\nCreating animal1:" << std::endl;
	Animal animal1;

	std::cout << "\nCreating animal2 as a copy of animal1:" << std::endl;
	Animal animal2(animal1);

	std::cout << "\nCreating animal3 and assigning animal1 to it:" << std::endl;
	Animal animal3;
	animal3 = animal1;

	std::cout << "\nExiting testAnimal function, objects should be destroyed now:" << std::endl;
}

int main()
{
	std::cout << "\033[1;32m=== Testing Animal Class ===\033[0m" << std::endl;
	testAnimal();
	std::cout << "\033[1;31m===Test Concluded===\033[0m" << std::endl;

	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();
	
	return 0;
}