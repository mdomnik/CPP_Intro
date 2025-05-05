/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:32:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:10:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form(void); //default constructor
		Form(std::string name, int gradeToSign, int gradeToExecute); //name/grade/execute constructor
		Form(const Form &other); //copy constructor
		Form & operator = (const Form &other); //copy assignment constructor
		~Form(void); //deconstructor

		//getters
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		//member functions
		void		beSigned(const Bureaucrat &bureaucrat);

		//exceptions
		class GradeTooHighException : public std::exception {
			const char * what() const throw() {
				return "Grade is too high";
			}
		};

		class GradeTooLowException : public std::exception {
			const char * what() const throw() {
				return "Grade is too low";
			}
		};

		class FormAlreadySignedException : public std::exception {
			const char * what() const throw() {
				return "Form is already signed";
			}
		};

};

//overloaded operator for Form
std::ostream & operator << (std::ostream &out, const Form &Form);

#endif