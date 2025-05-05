/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:32:38 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 15:46:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

// Default Constructor
Intern::Intern(void)
{
	std::cout << "Intern is created! (Default constructor)" << std::endl;
}

// Copy Constructor
Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
Intern& Intern::operator=(const Intern& other)
{
	(void)other; // Intern has no internal state
	std::cout << "Intern is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
Intern::~Intern(void)
{
	std::cout << "Intern is destroyed! (Destructor)" << std::endl;
}

// makeForm Function
AForm *Intern::makeForm(std::string formName, std::string target)
{
	typedef AForm *(Intern::*InternFuncs)(std::string target);
	
	InternFuncs formFuncs[3] = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			try
			{
				std::cout << "Intern creates " << formNames[i] << " form." << std::endl;
				return (this->*formFuncs[i])(target);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Intern: " << e.what() << std::endl;
				return NULL;
			}
		}
	}
	throw FormNotFoundException();
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
