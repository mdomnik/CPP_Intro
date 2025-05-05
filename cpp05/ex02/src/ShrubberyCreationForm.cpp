/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:46:42 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 14:07:34 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm with target: " << _target << " is created! (Default constructor)" << std::endl;
}

// Target Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm with target: " << _target << " is created! (Target constructor)" << std::endl;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm with target: " << _target << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "ShrubberyCreationForm with target: " << _target  << " is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm with target: " << _target << " is destroyed! (Destructor)" << std::endl;
}

// Execute Function
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
	{
		std::cerr << "Error: Could not open file for writing." << std::endl;
		return;
	}
	else
	{
		file    << "       *   \n"
				<< "      ***  \n"
				<< "     ***** \n"
				<< "    *******\n"
				<< "    *******\n"
				<< "     ***** \n"
				<< "      ***  \n"
				<< "       |   \n"
				<< "       |   \n"
				<< "     --|--\n"
				<< "     | | |\n"
				<< "     -----\n";
		file.close();
		std::cout << "Shrubbery created in file: " << _target << "_shrubbery" << std::endl;
	}
}