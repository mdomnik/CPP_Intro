/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:32:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:37:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm(void); //default constructor
		AForm(std::string name, int gradeToSign, int gradeToExecute); //name/grade/execute constructor
		AForm(const AForm &other); //copy constructor
		AForm & operator = (const AForm &other); //copy assignment constructor
		virtual ~AForm(void); //deconstructor

		//getters
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		//member functions
		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(const Bureaucrat &executor) const = 0; //pure virtual function

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

		class FormNotSignedException : public std::exception {
			const char * what() const throw() {
				return "Form is not signed";
			}
		};

};

//overloaded operator for Form
std::ostream & operator << (std::ostream &out, const AForm &Form);

#endif