/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:32:52 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/04 20:24:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include <iostream>

// Default Constructor
Form::Form(void): _name("Untitled"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form " << _name << " is created! (Default constructor)" << std::endl;
}

// name/grade/execute constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

	std::cout << "Form " << _name << " is created! (Name/Grade/Execute constructor)" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form " << _name << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
Form & Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	std::cout << "Form " << _name  << " is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << "Form " << _name << " is destroyed! (Destructor)" << std::endl;
}

// getName Function
std::string Form::getName(void) const
{
	return (this->_name);
}

// getSigned Function
bool Form::getSigned(void) const
{
	return (this->_signed);
}

// getGradeToSign Function
int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

// getGradeToExecute Function
int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

// beSigned Function
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->_signed)
		throw FormAlreadySignedException();
	this->_signed = true;
}

// Overload the << operator
std::ostream & operator << (std::ostream &out, const Form &form)
{
	out << "Form Name: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}


