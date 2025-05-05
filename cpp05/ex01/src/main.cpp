/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:05:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:12:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>

int main()
{
	// Valid Signing Test
	{
		std::cout << "\033[1;35m=== Valid Signing Test ===\033[0m" << std::endl;

		try {
			Bureaucrat Accountant("Accountant", 1);
			Form taxForm("Tax Form", 50, 100);

			std::cout << taxForm << std::endl;
			Accountant.signForm(taxForm);
			std::cout << taxForm << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Unexpected exception: " << e.what() << std::endl;
		}

		std::cout << "\033[1;35m=== Valid Signing Test Concluded ===\033[0m\n" << std::endl;
	}

	// Invalid Signing Test
	{
		std::cout << "\033[1;35m=== Invalid Signing Test ===\033[0m" << std::endl;

		try {
			Bureaucrat intern("Intern", 140);
			Form topSecret("Top Secret", 50, 100);

			std::cout << topSecret << std::endl;
			intern.signForm(topSecret);
			std::cout << topSecret << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Unexpected exception: " << e.what() << std::endl;
		}

		std::cout << "\033[1;35m=== Invalid Signing Test Concluded ===\033[0m\n" << std::endl;
	}

	// Invalid Form Construction Test
	{
		std::cout << "\033[1;35m=== Invalid Form Construction Test ===\033[0m" << std::endl;

		try {
			Form invalidForm1("Bad Form High", 0, 100); // Too high
		} catch (const std::exception& e) {
			std::cerr << "Caught exception for invalidForm1: " << e.what() << std::endl;
		}

		try {
			Form invalidForm2("Bad Form Low", 100, 151); // Too low
		} catch (const std::exception& e) {
			std::cerr << "Caught exception for invalidForm2: " << e.what() << std::endl;
		}

		std::cout << "\033[1;35m=== Invalid Form Construction Test Concluded ===\033[0m\n" << std::endl;
	}

	// Signing Already Signed Form Test
	{
		std::cout << "\033[1;35m=== Signing Already Signed Form Test ===\033[0m" << std::endl;

		try {
			Bureaucrat supervisor("Supervisor", 10);
			Form checklist("Checklist", 20, 50);

			supervisor.signForm(checklist); // First signing
			supervisor.signForm(checklist); // Should still pass, or do nothing depending on your design
			std::cout << checklist << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Unexpected exception: " << e.what() << std::endl;
		}

		std::cout << "\033[1;35m=== Signing Already Signed Form Test Concluded ===\033[0m\n" << std::endl;
	}

	// Display Format Test
	{
		std::cout << "\033[1;35m=== Display Format Test ===\033[0m" << std::endl;

		Form passport("Passport", 30, 60);
		std::cout << passport << std::endl;

		Bureaucrat officer("Officer", 25);
		std::cout << officer << std::endl;

		std::cout << "\033[1;35m=== Display Format Test Concluded ===\033[0m\n" << std::endl;
	}

	std::cout << "\033[1;32m=== All Form/Bureaucrat Tests Concluded ===\033[0m" << std::endl;
	return 0;
}
