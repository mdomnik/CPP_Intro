/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:06:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/04 18:14:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void); //default constructor
		Bureaucrat(std::string name, int grade); //name & grade constructor
		Bureaucrat(const Bureaucrat &other); //copy constructor
		Bureaucrat & operator = (const Bureaucrat &other); //copy assignment constructor
		~Bureaucrat(void); //deconstructor

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		decrementGrade(void);
		void		incrementGrade(void);

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
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif