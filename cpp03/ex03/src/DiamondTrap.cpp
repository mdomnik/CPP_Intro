/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:52:25 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/11 16:19:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"
#include <iostream>

//default constructor
DiamondTrap::DiamondTrap(void) : ClapTrap("Diamond_clap_name"), _name("DiamondTrap")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;	
	std::cout << "DiamondTrap " << _name << " is created! (Default constructor)" << std::endl;
}

//name constructor
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " is created! (Name constructor)" << std::endl;
}


//copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other._name + "_clap_name"), ScavTrap(other), FragTrap(other), _name(other._name)
{
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap " << _name << " is copied! (Copy constructor)" << std::endl;
}

//copy assignment constructor
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "DiamondTrap " << _name << " is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}



// Destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " is destroyed! (Destructor)" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	std::cout << "DiamondTrap " << _name << " uses ScavTrap's attack!" << std::endl;
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap: " << _name << " and my ClapTrap name is: " << ClapTrap::_name << "!" << std::endl;
}
