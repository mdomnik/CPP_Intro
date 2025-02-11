/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:25:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/06 18:00:37 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"
#include <iostream>

void testClapTrap()
{
	std::cout << "\nCreating ClapTrap1:" << std::endl;
	ClapTrap ClapTrap1;

	std::cout << "\nCreating ClapTrap2 as a copy of ClapTrap1:" << std::endl;
	ClapTrap ClapTrap2(ClapTrap1);

	std::cout << "\nCreating ClapTrap3 and assigning ClapTrap1 to it:" << std::endl;
	ClapTrap ClapTrap3;
	ClapTrap3 = ClapTrap1;

	std::cout << "\nExiting testClapTrap function, objects should be destroyed now:" << std::endl;
}

void testDiamondTrap()
{
	std::cout << "\nCreating DiamondTrap1:" << std::endl;
	DiamondTrap DiamondTrap1;

	std::cout << "\nCreating DiamondTrap2 as a copy of DiamondTrap1:" << std::endl;
	DiamondTrap DiamondTrap2(DiamondTrap1);

	std::cout << "\nCreating DiamondTrap3 and assigning DiamondTrap1 to it:" << std::endl;
	DiamondTrap DiamondTrap3;
	DiamondTrap3 = DiamondTrap1;

	std::cout << "\nExiting testDiamondTrap function, objects should be destroyed now:" << std::endl;
}

int main()
{
	{
		std::cout << "\033[1;32m=== Testing DiamondTrap Class ===\033[0m" << std::endl;
		testDiamondTrap();
		std::cout << "\033[1;31m===Test Concluded===\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;32m=== ClapTrap Testing Ground ===\033[0m" << std::endl;
		ClapTrap clappy("clappy");
			
		for (int i = 0; i < 7; i++) {
			clappy.attack("Bandit-01");
		}
			
		clappy.takeDamage(5);
		clappy.beRepaired(2);
		clappy.takeDamage(5);
		clappy.attack("Bandit-01");
		clappy.beRepaired(5);
		clappy.takeDamage(3);
		clappy.beRepaired(3);
		clappy.takeDamage(5);
	
		clappy.attack("Bandit-01");
		clappy.takeDamage(5);
		clappy.beRepaired(5);
		std::cout << "\033[1;31m===Test Concluded===\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;32m=== ScavTrap Testing Ground ===\033[0m" << std::endl;
		ScavTrap scavvy("scavvy");
			
		for (int i = 0; i < 7; i++) {
			scavvy.attack("Bandit-01");
		}
			
		scavvy.takeDamage(50);
		scavvy.beRepaired(20);
		scavvy.takeDamage(50);
		scavvy.attack("Bandit-01");
		scavvy.beRepaired(50);
		scavvy.takeDamage(30);
		scavvy.beRepaired(30);
		scavvy.guardGate();
		scavvy.takeDamage(1000);
	
		scavvy.attack("Bandit-01");
		scavvy.takeDamage(50);
		scavvy.beRepaired(50);
		scavvy.guardGate();
		std::cout << "\033[1;31m===Test Concluded===\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;32m=== FragTrap Testing Ground ===\033[0m" << std::endl;
		FragTrap fraggy("fraggy");
			
		for (int i = 0; i < 7; i++) {
			fraggy.attack("Bandit-01");
		}
			
		fraggy.takeDamage(50);
		fraggy.beRepaired(20);
		fraggy.takeDamage(50);
		fraggy.attack("Bandit-01");
		fraggy.beRepaired(50);
		fraggy.takeDamage(30);
		fraggy.beRepaired(30);
		fraggy.highFivesGuys();
		fraggy.takeDamage(1000);
	
		fraggy.attack("Bandit-01");
		fraggy.takeDamage(50);
		fraggy.beRepaired(50);
		fraggy.highFivesGuys();
		std::cout << "\033[1;31m===Test Concluded===\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;32m=== DiamondTrap Testing Ground ===\033[0m" << std::endl;
		DiamondTrap Diamonddy("Diamonddy");
			
		Diamonddy.attack("enemy");
		Diamonddy.takeDamage(40);
		Diamonddy.beRepaired(20);
		Diamonddy.guardGate();
		Diamonddy.highFivesGuys();
		Diamonddy.whoAmI();
		std::cout << "\033[1;31m===Test Concluded===\033[0m" << std::endl;
	}
}