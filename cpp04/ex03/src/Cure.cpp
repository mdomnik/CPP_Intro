/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:46:28 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 03:41:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include <iostream>

// Default Constructor
Cure::Cure(void)
{
	type = "cure";
}

// Copy Constructor
Cure::Cure(const Cure &other) : AMateria(other) {}

// Copy Assignment Operator
Cure & Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

// Destructor
Cure::~Cure() {}

//clone function
Cure* Cure::clone() const
{
    return new Cure(*this);
}


//use function
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}