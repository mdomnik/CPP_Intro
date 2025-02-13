/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:58:45 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 01:01:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"
#include <iostream>

// Default Constructor
AAnimal::AAnimal(void): type("Animal")
{
	std::cout << "AAnimal " << type << " is created! (Default constructor)" << std::endl;
}

// Copy Constructor
AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "AAnimal " << type << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
AAnimal & AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "AAnimal " << type << " is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << type << " is destroyed! (Destructor)" << std::endl;
}

// Getter
std::string AAnimal::getType(void) const { return (type); }
