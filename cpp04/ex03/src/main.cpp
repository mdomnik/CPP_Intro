/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:19:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 04:36:43 by mdomnik          ###   ########.fr       */
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

		Character gabbro("Gabbro");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();

		gabbro.equip(ice);
		gabbro.equip(cure);

		Character gabbroCopy(gabbro); // Deep copy test

		std::cout << "gabbro uses materia:\n";
		gabbro.use(0, gabbro);
		gabbro.use(1, gabbro);

		std::cout << "gabbroCopy uses materia:\n";
		gabbroCopy.use(0, gabbroCopy);
		gabbroCopy.use(1, gabbroCopy);

		
		gabbroCopy.unequip(0);
		gabbroCopy.unequip(1);
		
		std::cout << "gabbro still has its materia:\n";
		gabbro.use(0, gabbro);
		gabbro.use(1, gabbro);

		std::cout << "\033[1;35m=== Deep Copy Test Concluded ===\033[0m" << std::endl;
	}

	// Full Inventory Test
	{
		std::cout << "\033[1;35m\n=== Full Inventory Test ===\033[0m" << std::endl;

		Character feldspar("feldspar");
		AMateria* ice1 = new Ice();
		AMateria* ice2 = new Ice();
		AMateria* cure1 = new Cure();
		AMateria* cure2 = new Cure();
		AMateria* extra = new Ice();

		feldspar.equip(ice1);
		feldspar.equip(ice2);
		feldspar.equip(cure1);
		feldspar.equip(cure2);

		feldspar.equip(extra); // Should not be added

		std::cout << "Using all slots:\n";
		for (int i = 0; i < 4; i++)
			feldspar.use(i, feldspar);
		delete extra;
		std::cout << "\033[1;35m=== Full Inventory Test Concluded ===\033[0m" << std::endl;
	}

	// Unequip Handling Test
	{
		std::cout << "\033[1;35m\n=== Unequip Handling Test ===\033[0m" << std::endl;

		Character riebeck("riebeck");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();

		riebeck.equip(ice);
		riebeck.equip(cure);

		std::cout << "Using before unequip:\n";
		riebeck.use(0, riebeck);
		riebeck.use(1, riebeck);

		riebeck.unequip(0); // Should not delete ice

		std::cout << "Using unequipped slot (should do nothing):\n";
		riebeck.use(0, riebeck);

		std::cout << "\033[1;35m=== Unequip Handling Test Concluded ===\033[0m" << std::endl;
	}

	// Materia Source Learning & Creating
	{
		std::cout << "\033[1;35m\n=== Materia Source Learning & Creating ===\033[0m" << std::endl;

		MateriaSource source;
		source.learnMateria(new Ice());
		source.learnMateria(new Cure());

		AMateria* createdIce = source.createMateria("ice");
		AMateria* createdCure = source.createMateria("cure");
		AMateria* unknownMateria = source.createMateria("fire");

		if (createdIce)
			std::cout << "Created Ice successfully\n";
		if (createdCure)
			std::cout << "Created Cure successfully\n";
		if (!unknownMateria)
			std::cout << "Unknown Materia\n";

		delete createdIce;
		delete createdCure;

		std::cout << "\033[1;35m=== Materia Source Learning & Creating Concluded ===\033[0m" << std::endl;
	}

	std::cout << "\033[1;32m\n=== All Tests Concluded ===\033[0m\n" << std::endl;
	return 0;
}
