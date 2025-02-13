/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:39:58 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 04:29:41 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include <iostream>

AMateria* Character::materiasDropped[FloorSpace] = { NULL };
int Character::dropped = 0;

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
	if (dropped > 0)
	{
		std::cout << "Cleaning up dropped Materia...\n";
		for (int i = 0; i < dropped; i++)
		{
			if (materiasDropped[i])
			{
				delete materiasDropped[i];
				materiasDropped[i] = NULL;
			}
		}
		dropped = 0;
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
	{
		if (dropped < FloorSpace)
		{
			materiasDropped[dropped] = slot[idx];
			dropped++;
		}
		else
		{
			std::cout << "Too Many items on the floor, removing all..." << std::endl;
			for (int i = 0; i < dropped; i++)
			{
				delete materiasDropped[i];
				materiasDropped[i] = NULL;
			}
			std::cout << "Floor Cleared!" << std::endl;
			dropped = 0;
			materiasDropped[dropped] = slot[idx];
			dropped++;
		}
		slot[idx] = NULL;
	}
}

// Use Materia
void Character::use(int idx, ICharacter &target)
{
		if (idx >= 0 && idx < 4)
			if (slot[idx])
				slot[idx]->use(target);
}