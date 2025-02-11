/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:25:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/05 15:14:54 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iostream>

int main()
{
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
		return (0);
	}
}