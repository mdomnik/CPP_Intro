/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:19:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 04:03:53 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"
#include <iostream>

int main()
{
	// Default Materia test
	{
		std::cout << "\033[1;35m=== Default Materia Test ===\033[0m" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		std::cout << "\033[1;35m=== Default Materia Test Concluded ===\033[0m" << std::endl;
	}

	// Deep Copy Test
	{
		std::cout << "\033[1;35m\n=== Deep Copy Test ===\033[0m" << std::endl;

		Character original("Gabbro");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();

		original.equip(ice);
		original.equip(cure);

		Character copied(original); // Deep copy test

		std::cout << "Original uses materia:\n";
		original.use(0, original);
		original.use(1, original);

		std::cout << "Copied uses materia:\n";
		copied.use(0, copied);
		copied.use(1, copied);

		
		copied.unequip(0);
		copied.unequip(1);
		
		std::cout << "Original still has its materia:\n";
		original.use(0, original);
		original.use(1, original);

		std::cout << "\033[1;35m=== Deep Copy Test Concluded ===\033[0m" << std::endl;
	}

	// // Full Inventory Test
	// {
	// 	std::cout << "\033[1;35m=== Full Inventory Test ===\033[0m" << std::endl;

	// 	Character mage("Mage");
	// 	AMateria* ice1 = new Ice();
	// 	AMateria* ice2 = new Ice();
	// 	AMateria* cure1 = new Cure();
	// 	AMateria* cure2 = new Cure();
	// 	AMateria* extra = new Ice();

	// 	mage.equip(ice1);
	// 	mage.equip(ice2);
	// 	mage.equip(cure1);
	// 	mage.equip(cure2);

	// 	std::cout << "Trying to equip an extra materia (should not be added):\n";
	// 	mage.equip(extra); // Should not be added

	// 	std::cout << "Using all slots:\n";
	// 	for (int i = 0; i < 4; i++) {
	// 		mage.use(i, mage);
	// 	}

	// 	delete extra;
	// 	std::cout << "\033[1;35m=== Full Inventory Test Concluded ===\033[0m" << std::endl;
	// }

	// // Unequip Handling Test
	// {
	// 	std::cout << "\033[1;35m=== Unequip Handling Test ===\033[0m" << std::endl;

	// 	Character warrior("Warrior");
	// 	AMateria* ice = new Ice();
	// 	AMateria* cure = new Cure();

	// 	warrior.equip(ice);
	// 	warrior.equip(cure);

	// 	// Store reference before unequipping
	// 	AMateria* savedMateria = ice;

	// 	std::cout << "Using before unequip:\n";
	// 	warrior.use(0, warrior);
	// 	warrior.use(1, warrior);

	// 	warrior.unequip(0); // Should not delete ice

	// 	std::cout << "Using unequipped slot (should do nothing):\n";
	// 	warrior.use(0, warrior);

	// 	delete savedMateria;
	// 	delete cure;

	// 	std::cout << "\033[1;35m=== Unequip Handling Test Concluded ===\033[0m" << std::endl;
	// }

	// // Materia Source Learning & Creating
	// {
	// 	std::cout << "\033[1;35m=== Materia Source Learning & Creating ===\033[0m" << std::endl;

	// 	MateriaSource source;
	// 	source.learnMateria(new Ice());
	// 	source.learnMateria(new Cure());

	// 	AMateria* createdIce = source.createMateria("ice");
	// 	AMateria* createdCure = source.createMateria("cure");
	// 	AMateria* unknownMateria = source.createMateria("fire");

	// 	if (createdIce) std::cout << "Created Ice successfully.\n";
	// 	if (createdCure) std::cout << "Created Cure successfully.\n";
	// 	if (!unknownMateria) std::cout << "Unknown Materia creation returned NULL as expected.\n";

	// 	delete createdIce;
	// 	delete createdCure;

	// 	std::cout << "\033[1;35m=== Materia Source Learning & Creating Concluded ===\033[0m" << std::endl;
	// }

	// // Edge Cases Test
	// {
	// 	std::cout << "\033[1;35m=== Edge Cases Test ===\033[0m" << std::endl;

	// 	Character rogue("Rogue");

	// 	// Unequip when inventory is empty
	// 	std::cout << "Trying to unequip from an empty inventory:\n";
	// 	rogue.unequip(0);

	// 	// Use non-existent materia
	// 	std::cout << "Trying to use an empty slot:\n";
	// 	rogue.use(0, rogue);

	// 	// Equip NULL
	// 	std::cout << "Trying to equip NULL Materia:\n";
	// 	rogue.equip(NULL);

	// 	std::cout << "\033[1;35m=== Edge Cases Test Concluded ===\033[0m" << std::endl;
	// }

	std::cout << "\033[1;35m=== All Tests Concluded ===\033[0m\n" << std::endl;
	return 0;
}
