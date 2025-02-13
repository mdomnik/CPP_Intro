/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:53:47 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:01:39 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include <iostream>

// Default Constructor
WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "WrongCat is created! (Default constructor)" << std::endl;
}

// Copy Constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
WrongCat & WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongCat is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destroyed! (Destructor)" << std::endl;
}

// makeSound() implementation
void WrongCat::makeSound(void) const
{
	std::cout << "WrongMeow!" << std::endl;
}
