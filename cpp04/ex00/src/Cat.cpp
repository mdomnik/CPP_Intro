/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:09 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:12:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>

// Default Constructor
Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Cat is created! (Default constructor)" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
Cat & Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Cat is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat is destroyed! (Destructor)" << std::endl;
}

// makeSound function
void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
