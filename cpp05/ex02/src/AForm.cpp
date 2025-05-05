/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:32:52 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:22:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include <iostream>

// Default Constructor
AForm::AForm(void): _name("Untitled"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm " << _name << " is created! (Default constructor)" << std::endl;
}

// name/grade/execute constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

	std::cout << "AForm " << _name << " is created! (Name/Grade/Execute constructor)" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm " << _name << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
AForm & AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	std::cout << "AForm " << _name  << " is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm " << _name << " is destroyed! (Destructor)" << std::endl;
}

// getName Function
std::string AForm::getName(void) const
{
	return (this->_name);
}

// getSigned Function
bool AForm::getSigned(void) const
{
	return (this->_signed);
}

// getGradeToSign Function
int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

// getGradeToExecute Function
int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

// beSigned Function
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->_signed)
		throw FormAlreadySignedException();
	this->_signed = true;
}

// Overload the << operator
std::ostream & operator << (std::ostream &out, const AForm &form)
{
	out << "AForm Name: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}


