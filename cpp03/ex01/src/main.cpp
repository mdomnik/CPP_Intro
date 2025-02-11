/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:25:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/11 16:36:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
#include <iostream>

int main()
{
	// ========================== ClapTrap Testing ==========================
	{
		{
			std::cout << "\033[1;32m=== ClapTrap Constructor Testing ===\033[0m" << std::endl;
			
			ClapTrap defaultClap;
			ClapTrap namedClap("Clappy");
			ClapTrap copyClap(namedClap);
			ClapTrap assignedClap;
			assignedClap = namedClap;
			
			std::cout << "\033[1;34m=== ClapTrap Functionality Testing ===\033[0m" << std::endl;
			
			namedClap.attack("Bandit-01");
			namedClap.takeDamage(3);
			namedClap.beRepaired(2);
			copyClap.attack("Bandit-02");
			assignedClap.takeDamage(5);
			assignedClap.beRepaired(4);
			std::cout << "\033[1;31m=== Test Concluded ===\033[0m" << std::endl;
		}
		{
			std::cout << "\033[1;34m=== ClapTrap Testing Ground ===\033[0m" << std::endl;
			ClapTrap clappy("Clappy");
			
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
			std::cout << "\033[1;31m=== ClapTrap Test Concluded ===\033[0m" << std::endl;
		}
	}
		
	// ========================== ScavTrap Testing ==========================
	{
		{
			std::cout << "\033[1;32m=== ScavTrap Constructor Testing ===\033[0m" << std::endl;
			
			ScavTrap defaultScav;
			ScavTrap namedScav("Scavvy");
			ScavTrap copyScav(namedScav);
			ScavTrap assignedScav;
			assignedScav = namedScav;
			
			std::cout << "\033[1;34m=== ScavTrap Functionality Testing ===\033[0m" << std::endl;
			
			namedScav.attack("Bandit-01");
			namedScav.takeDamage(20);
			namedScav.beRepaired(10);
			namedScav.guardGate();
			
			copyScav.attack("Bandit-02");
			assignedScav.takeDamage(30);
			assignedScav.beRepaired(15);
			assignedScav.guardGate();
			std::cout << "\033[1;31m=== Test Concluded ===\033[0m" << std::endl;
		}
		{
			std::cout << "\033[1;34m=== ScavTrap Testing Ground ===\033[0m" << std::endl;
			ScavTrap scavvy("Scavvy");
			
			for (int i = 0; i < 5; i++) {
				scavvy.attack("Bandit-01");
			}
			
			scavvy.takeDamage(50);
			scavvy.beRepaired(20);
			scavvy.guardGate();
				
			scavvy.takeDamage(50);
			scavvy.attack("Bandit-01");
			scavvy.beRepaired(50);
			scavvy.guardGate();
			
			std::cout << "\033[1;31m=== ScavTrap Test Concluded ===\033[0m" << std::endl;
		}
	}
	return 0;
}