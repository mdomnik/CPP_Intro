/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:24:23 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:54:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain(void); //default constructor
		Brain(const Brain &other); //copy constructor
		Brain & operator = (const Brain &other); //copy assignment constructor
		~Brain(void); //deconstructor

		void setIdea(int i, const std::string& str);
		std::string getIdea(int i) const;
};

#endif