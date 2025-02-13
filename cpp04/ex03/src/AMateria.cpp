/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:35:35 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 03:47:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include <iostream>

// Default Constructor
AMateria::AMateria(void): type("AMateria") {}

//type constructor
AMateria::AMateria(std::string const & type) : type(type) {}

// Copy Constructor
AMateria::AMateria(const AMateria &other) : type(other.type) {}

// Copy Assignment Operator
AMateria & AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

// Destructor
AMateria::~AMateria() {}

// Getter
std::string const & AMateria::getType(void) const { return (type); }

//use function
void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "No Materia Selected ..." << std::endl;
}