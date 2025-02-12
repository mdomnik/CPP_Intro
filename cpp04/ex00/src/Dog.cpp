/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:12:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>

// Default Constructor
Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Dog " << type << " is created! (Default constructor)" << std::endl;
}

// Copy Contructor
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog " << type << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment operator
Dog & Dog::operator=(const Dog &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Dog " << type << " is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Deconstructor
Dog::~Dog() {
	std::cout << "Dog " << type << " is destroyed! (Destructor)" << std::endl;
}

// makeSound function
void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
