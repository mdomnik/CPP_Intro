/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:05:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 15:45:14 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	// Valid Form Creation + Signing + Execution
	{
		std::cout << "\033[1;35m=== Full Form Lifecycle Test ===\033[0m" << std::endl;

		Intern intern;
		Bureaucrat highRank("HighRank", 1);

		const std::string formNames[] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
		const std::string targets[] = {
			"Backyard",
			"Bender",
			"Arthur Dent"
		};

		for (int i = 0; i < 3; ++i)
		{
			AForm* form = intern.makeForm(formNames[i], targets[i]);
			if (form)
			{
				std::cout << *form << std::endl;

				// Try to execute before signing
				try {
					highRank.executeForm(*form);
				} catch (const std::exception& e) {
					std::cerr << "Expected (not signed): " << e.what() << std::endl;
				}

				// Now sign and execute
				highRank.signForm(*form);
				try {
					highRank.executeForm(*form);
				} catch (const std::exception& e) {
					std::cerr << "Unexpected execution failure: " << e.what() << std::endl;
				}

				delete form;
				std::cout << "\033[1;34m---\033[0m" << std::endl;
			}
		}

		std::cout << "\033[1;35m=== Full Form Lifecycle Test Concluded ===\033[0m\n" << std::endl;
	}

	// Failure to Create Unknown Form
	{
		std::cout << "\033[1;35m=== Intern Fails on Unknown Form ===\033[0m" << std::endl;

		Intern intern;
		try {
			AForm* fake = intern.makeForm("dinner reservation", "Restaurant at End of Universe");
			if (fake)
			{
				std::cerr << "ERROR: Unexpected success." << std::endl;
				delete fake;
			}
		} catch (const std::exception& e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}

		std::cout << "\033[1;35m=== Unknown Form Test Concluded ===\033[0m\n" << std::endl;
	}

	// Execution Failure Due to Low Grade
	{
		std::cout << "\033[1;35m=== Execution Grade Too Low Test ===\033[0m" << std::endl;

		Intern intern;
		Bureaucrat lowRank("LowRank", 150);
		AForm* form = intern.makeForm("shrubbery creation", "PublicPark");

		if (form)
		{
			lowRank.signForm(*form);  // should fail
			try {
				lowRank.executeForm(*form); // should fail too
			} catch (const std::exception& e) {
				std::cerr << "Execution failed as expected: " << e.what() << std::endl;
			}
			delete form;
		}

		std::cout << "\033[1;35m=== Execution Grade Too Low Test Concluded ===\033[0m\n" << std::endl;
	}

	std::cout << "\033[1;32m=== All Intern/Form Execution Tests Concluded ===\033[0m\n" << std::endl;
	return 0;
}