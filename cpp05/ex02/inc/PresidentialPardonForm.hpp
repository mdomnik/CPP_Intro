/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:24:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:34:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm(void); //default constructor
		PresidentialPardonForm(std::string target); //target constructor
		PresidentialPardonForm(const PresidentialPardonForm &other); //copy constructor
		PresidentialPardonForm & operator = (const PresidentialPardonForm &other); //copy assignment constructor
		virtual ~PresidentialPardonForm(void); //deconstructor

		void execute(const Bureaucrat &executor) const;
};

#endif