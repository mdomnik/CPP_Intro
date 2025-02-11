/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:32:56 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/05 14:42:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include <iostream>

//default constructor
FragTrap::FragTrap(void) : ClapTrap()
{
	_name = "FragTrap";
	std::cout << "FragTrap " << _name << " is created! (Default constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

//nane constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " is created! (Name constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

//copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " is copied! (Copy constructor)" << std::endl;
	*this = other;
}

//copy assignment constructor
FragTrap & FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap " << _name << " is assigned! (Copy assignment constructor)" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

// Destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destroyed! (Destructor)" << std::endl;
}

//attack function
void FragTrap::attack(std::string const &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else if (_hitPoints == 0)
		std::cout << "FragTrap " << _name << "; a destroyed unit can't attack anymore!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " is out of energy and can't attack anymore!" << std::endl;
}

//highFivesGuys function
void FragTrap::highFivesGuys(void)
{
	if (_hitPoints > 0)
		std::cout << "High Fives Guys!!!" << std::endl;
	else
		std::cout << "FragTrap " << _name << "; a destroyed unit can't high five!" << std::endl;
}