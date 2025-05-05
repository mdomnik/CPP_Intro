/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:24:08 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:40:37 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
	public:
		RobotomyRequestForm(void); //default constructor
		RobotomyRequestForm(std::string target); //target constructor
		RobotomyRequestForm(const RobotomyRequestForm &other); //copy constructor
		RobotomyRequestForm & operator = (const RobotomyRequestForm &other); //copy assignment constructor
		virtual ~RobotomyRequestForm(void); //deconstructor

		void execute(const Bureaucrat &executor) const;
};

#endif