/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 00:11:27 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>

// Default Constructor
Dog::Dog(void)
{
	type = "Dog";
	brain = new Brain;
	std::cout << "Dog " << type << " is created! (Default constructor)" << std::endl;
}

// Copy Contructor
Dog::Dog(const Dog &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog " << type << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain); // Deep copy
	}
	std::cout << "Dog is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Deconstructor
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog " << type << " is destroyed! (Destructor)" << std::endl;
}

// makeSound function
void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

//getter ideas
std::string Dog::getIdea(int i) const
{
	return(brain->getIdea(i));
}

//setter ideas
void Dog::setIdea(int i, const std::string &str)
{
	brain->setIdea(i, str);
}
