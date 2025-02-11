/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:32:56 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/11 16:06:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include <iostream>

//default constructor
FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is created! (Default constructor)" << std::endl;
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
}


//copy assignment constructor
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap " << _name << " is assigned from " << other._name << "! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " is destroyed! (Destructor)" << std::endl;
}

//attack function
void FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap " << _name << " prepares to attack!" << std::endl;
	ClapTrap::attack(target);
}

//highFivesGuys function
void FragTrap::highFivesGuys(void)
{
	if (_hitPoints > 0)
		std::cout << "High Fives Guys!!!" << std::endl;
	else
		std::cout << "FragTrap " << _name << "; a destroyed unit can't high five!" << std::endl;
}