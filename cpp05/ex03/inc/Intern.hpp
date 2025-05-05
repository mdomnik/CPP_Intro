/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:28:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 14:45:32 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

class Intern
{
	public:
		Intern(void); //default constructor
		Intern(const Intern &other); //copy constructor
		Intern & operator = (const Intern &other); //copy assignment constructor
		~Intern(void); //deconstructor

		//member functions
		AForm *makeForm(std::string formName, std::string target);
		AForm *makePresidentialPardonForm(std::string target);
		AForm *makeShrubberyCreationForm(std::string target);
		AForm *makeRobotomyRequestForm(std::string target);
		
		//exceptions
		class FormNotFoundException : public std::exception {
			const char * what() const throw() {
				return "Form not found";
			}
		};
};

#endif