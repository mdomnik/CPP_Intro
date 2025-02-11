/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:26:01 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/11 15:35:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include <iostream>

//default constructor
ClapTrap::ClapTrap() : _name("claptrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is created! (Default constructor)" << std::endl;
}

//name constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is created! (Name constructor)" << std::endl;
}
//copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) :
    _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " is copied from " << other._name << "! (Copy constructor)" << std::endl;
}


//copy assignment constructor
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << _name << " is assigned! (Copy assignment operator)" << std::endl;
	}
	return *this;
}

//deconstructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed! (Destructor)" << std::endl;
}
//attack function
void ClapTrap::attack(std::string const &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << "; a destroyed unit can't attack anymore!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is out of energy and can't attack anymore!" << std::endl;
}
//take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << "; a destroyed unit can't take damage!" << std::endl;
		return;
	}
	if ((int)amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! (" << _hitPoints << "hp)" << std::endl;
}

//repair function
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << "; a destroyed unit can't repair itself!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to repair itself!" << std::endl;
		return;
	}

	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points! (" << _hitPoints << "hp)" << std::endl;
}