/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:49:48 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:13:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include <iostream>

// Default Constructor
WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << "WrongAnimal " << type << " is created! (Default constructor)" << std::endl;
}

// Name Constructor
WrongAnimal::WrongAnimal(std::string name) : type(name)
{
	std::cout << "WrongAnimal " << type << " is created! (Name constructor)" << std::endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "WrongAnimal " << type << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "WrongAnimal " << type << " is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << type << " is destroyed! (Destructor)" << std::endl;
}

// Default makeSound() method
void WrongAnimal::makeSound(void) const
{
	std::cout << "Random WrongAnimal sound!" << std::endl;
}

// Getter
std::string WrongAnimal::getType(void) const { return (type); }
