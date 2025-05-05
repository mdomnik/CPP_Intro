/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:23:42 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/05 13:48:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm(void); //default constructor
		ShrubberyCreationForm(std::string target); //target constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other); //copy constructor
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm &other); //copy assignment constructor
		virtual ~ShrubberyCreationForm(void); //deconstructor

		void execute(const Bureaucrat &executor) const;
};

#endif