/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:15:44 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/05 14:30:32 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
#include <iostream>

//default constructor
ScavTrap::ScavTrap(void) : ClapTrap()
{
	_name = "ScavTrap";
	std::cout << "ScavTrap " << _name << " is created! (Default constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
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
	*this = other;
}

//copy assignment constructor
ScavTrap & ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap " << _name << " is assigned! (Copy assignment constructor)" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

// Destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destroyed! (Destructor)" << std::endl;
}

//attack function
void ScavTrap::attack(std::string const &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << "; a destroyed unit can't attack anymore!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is out of energy and can't attack anymore!" << std::endl;
}

//guardGate function
void ScavTrap::guardGate()
{
	if (_energyPoints > 0 && _hitPoints > 0)
		std::cout << "ScavTrap " << _name << " is guarding the gate!"<< std::endl;
	else if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << "; a destroyed unit can't guard the gate"<< std::endl;
	else
		std::cout << "ScavTrap " << _name << "; is too exhausted guard the gate"<< std::endl;
}
