/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:05:54 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/04 18:32:52 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <iostream>

// Default Constructor
Bureaucrat::Bureaucrat(void): _name("John Doe"), _grade(1)
{
	std::cout << "Bureaucrat " << _name << " is created! (Default constructor)" << std::endl;
}

// name & grade constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat " << _name << " (grade: "<< _grade << ")" << " is created! (Name & Grade constructor)" << std::endl;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " << _name << " (grade: "<< _grade << ") is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
Bureaucrat & Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << "Bureaucrat " << _name << " (grade: " << _grade << ") is assigned! (Copy assignment operator)" << std::endl;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " (grade: "<< _grade << ") is destroyed! (Destructor)" << std::endl;
}

// getName Function
std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

// getGrade Function
int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// decrementGrade Function
void Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

// incrementGrade Function
void Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
