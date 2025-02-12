/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:42:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:12:53 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>

// Default Constructor
Animal::Animal(void): type("Animal")
{
	std::cout << "Animal " << type << " is created! (Default constructor)" << std::endl;
}

// name constructor
Animal::Animal(std::string name) : type(name)
{
	std::cout << "Animal " << type << " is created! (Name constructor)" << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal " << type << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
Animal & Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal " << type << " is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Destructor
Animal::~Animal() {
	std::cout << "Animal " << type << " is destroyed! (Destructor)" << std::endl;
}

// Default makeSound() method
void Animal::makeSound(void) const
{
	std::cout << "Random animal sound!" << std::endl;
}

// Getter
std::string Animal::getType(void) const { return (type); }
