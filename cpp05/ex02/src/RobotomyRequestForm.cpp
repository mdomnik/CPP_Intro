/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:41:59 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:45:21 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm with target: " << _target << " is created! (Default constructor)" << std::endl;
}

// Target Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm with target: " << _target << " is created! (Target constructor)" << std::endl;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm with target: " << _target << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "RobotomyRequestForm with target: " << _target  << " is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm with target: " << _target << " is destroyed! (Destructor)" << std::endl;
}

// Execute Function
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	int random = std::rand();
	std::cout << "Robotomy in progress..." << std::endl;
	std::cout << "*drilling noises*" << std::endl;
	if (random % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << _target << "." << std::endl;
}