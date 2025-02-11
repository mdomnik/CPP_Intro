/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:15:44 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/11 15:43:54 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
#include <iostream>

//default constructor
ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " is created! (Default constructor)" << std::endl;
}

//nane constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " is created! (Name constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " is copied! (Copy constructor)" << std::endl;
}

//copy assignment constructor
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap " << _name << " is assigned from " << other._name << "! (Copy assignment operator)" << std::endl;
	return *this;
}


// Destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " is destroyed! (Destructor)" << std::endl;
}

//attack function
void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << _name << " prepares to attack!" << std::endl;
	ClapTrap::attack(target);
}


//guardGate function
void ScavTrap::guardGate()
{
	if (_hitPoints > 0)
		std::cout << "ScavTrap " << _name << " is guarding the gate!"<< std::endl;
	else
		std::cout << "ScavTrap " << _name << "; a destroyed unit can't guard the gate"<< std::endl;
}
