/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:09 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 00:10:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>

// Default Constructor
Cat::Cat(void)
{
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat is created! (Default constructor)" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
Cat & Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Destructor
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat is destroyed! (Destructor)" << std::endl;
}

// makeSound function
void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

//getter ideas
std::string Cat::getIdea(int i) const
{
	return(brain->getIdea(i));
}

//setter ideas
void Cat::setIdea(int i, const std::string &str)
{
	brain->setIdea(i, str);
}
