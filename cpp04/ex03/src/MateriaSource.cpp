/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:43:57 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 03:49:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"
#include <iostream>

// Default Constructor
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		sources[i] = NULL;
}

// Copy Constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.sources[i])
			sources[i] = other.sources[i]->clone();
		else
			sources[i] = NULL;
	}
}

// Copy Assignment Operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (sources[i])
				delete sources[i];
			if (other.sources[i])
				sources[i] = other.sources[i]->clone();
			else
				sources[i] = NULL;
		}
	}
	return *this;
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (sources[i])
			delete sources[i];
	}
}

// Learn Materia
void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!sources[i])
		{
			sources[i] = m->clone();
			delete m;
			break;
		}
	}
}

// Create Materia
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (sources[i] && sources[i]->getType() == type)
		{
			return sources[i]->clone();
		}
	}
	return NULL;
}