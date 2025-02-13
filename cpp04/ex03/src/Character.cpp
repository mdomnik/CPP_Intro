/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:39:58 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 04:01:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include <iostream>

// Default Constructor
Character::Character() : name("John")
{
	for (int i = 0; i < 4; ++i)
		slot[i] = NULL;
}

// Name Constructor
Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; ++i)
		slot[i] = NULL;
}

// Copy Constructor
Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.slot[i])
			slot[i] = other.slot[i]->clone();
		else
			slot[i] = NULL;
	}
}

// Copy Assignment Operator
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; ++i)
		{
			if (slot[i])
			{
				delete slot[i];
				slot[i] = NULL;
			}

			if (other.slot[i])
				slot[i] = other.slot[i]->clone();
			else
				slot[i] = NULL;
		}
	}
	return (*this);
}


// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (slot[i])
		{
			delete slot[i];
			slot[i] = NULL;
		}
	}
}

// Get Name
std::string const &Character::getName() const
{
	return (name);
}

// Equip Materia
void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!slot[i])
		{
			slot[i] = m;
			break;
		}
	}
}

// Unequip Materia
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		slot[idx] = NULL;
}

// Use Materia
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && slot[idx])
		slot[idx]->use(target);
}