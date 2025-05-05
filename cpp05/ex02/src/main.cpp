/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:05:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 14:20:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>

int main() {

	// Basic Shrubbery Creation
	{
		std::cout << "\033[1;35m=== Shrubbery Creation Test ===\033[0m" << std::endl;
		try {
			Bureaucrat gardener("Gardener", 130);
			ShrubberyCreationForm form("Home");

			gardener.signForm(form);
			gardener.executeForm(form);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Shrubbery Creation Test Concluded ===\033[0m\n" << std::endl;
	}

	// Robotomy Repeated Execution
	{
		std::cout << "\033[1;35m=== Robotomy Request Test ===\033[0m" << std::endl;
		try {
			Bureaucrat Doctor("Doctor", 40);
			RobotomyRequestForm form("Patient");

			Doctor.signForm(form);
			for (int i = 0; i < 5; ++i)
				Doctor.executeForm(form);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Robotomy Request Test Concluded ===\033[0m\n" << std::endl;
	}

	// Pardon Test With Perfect Grade
	{
		std::cout << "\033[1;35m=== Presidential Pardon Test ===\033[0m" << std::endl;
		try {
			Bureaucrat pres("President", 1);
			PresidentialPardonForm form("Arthur Dent");

			pres.signForm(form);
			pres.executeForm(form);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Presidential Pardon Test Concluded ===\033[0m\n" << std::endl;
	}

	// Attempt to Execute Unsigned Form
	{
		std::cout << "\033[1;35m=== Execute Unsigned Form Test ===\033[0m" << std::endl;
		try {
			Bureaucrat dev("Dev", 10);
			RobotomyRequestForm form("BetaTest");

			dev.executeForm(form); // Not signed yet
		} catch (std::exception &e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Execute Unsigned Form Test Concluded ===\033[0m\n" << std::endl;
	}

	// Signing and Execution at Threshold Grade
	{
		std::cout << "\033[1;35m=== Exact Grade Success Test ===\033[0m" << std::endl;
		try {
			Bureaucrat justEnough("Qualified", 72);
			RobotomyRequestForm form("Patient");

			justEnough.signForm(form);
			justEnough.incrementGrade(); // Now grade 71
			justEnough.executeForm(form);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Exact Grade Success Test Concluded ===\033[0m\n" << std::endl;
	}

	// Two Bureaucrats, One Form
	{
		std::cout << "\033[1;35m=== Multiple Bureaucrats Test ===\033[0m" << std::endl;
		try {
			Bureaucrat alice("Alice", 100);
			Bureaucrat bob("Bob", 130);
			ShrubberyCreationForm form("tree_house");

			bob.signForm(form);    // Fails
			alice.signForm(form);  // Succeeds
			bob.executeForm(form); // Fails
			alice.executeForm(form); // Succeeds
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Multiple Bureaucrats Test Concluded ===\033[0m\n" << std::endl;
	}

	// Re-sign Attempt Test
	{
		std::cout << "\033[1;35m=== Re-signing Test ===\033[0m" << std::endl;
		try {
			Bureaucrat signer("Signer", 20);
			PresidentialPardonForm form("Ford Prefect");

			signer.signForm(form);
			signer.signForm(form); // Should not throw, may output nothing or a message
			signer.executeForm(form);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Re-signing Test Concluded ===\033[0m\n" << std::endl;
	}

	// Display Format Test
	{
		std::cout << "\033[1;35m=== Display Format Test ===\033[0m" << std::endl;
		PresidentialPardonForm form("Random Citizen");
		std::cout << form << std::endl;

		Bureaucrat reporter("Press Officer", 10);
		std::cout << reporter << std::endl;
		std::cout << "\033[1;35m=== Display Format Test Concluded ===\033[0m\n" << std::endl;
	}

	std::cout << "\033[1;32m=== All Extended AForm Tests Concluded ===\033[0m" << std::endl;
	return 0;
}