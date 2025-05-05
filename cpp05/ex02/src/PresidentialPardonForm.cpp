/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:27:54 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:35:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm with target: " << _target << " is created! (Default constructor)" << std::endl;
}

// Target Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm with target: " << _target << " is created! (Target constructor)" << std::endl;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm with target: " << _target << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "PresidentialPardonForm with target: " << _target  << " is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm with target: " << _target << " is destroyed! (Destructor)" << std::endl;
}

// Execute Function
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}