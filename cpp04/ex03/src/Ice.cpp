/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:46:49 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 04:04:37 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"
#include <iostream>

// Default Constructor
Ice::Ice(void)
{
	type = "ice";
}

// Copy Constructor
Ice::Ice(const Ice &other) : AMateria(other) {}

// Copy Assignment Operator
Ice & Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

// Destructor
Ice::~Ice() {}

//clone function
Ice* Ice::clone() const
{
	return new Ice(*this);
}

//use function
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}