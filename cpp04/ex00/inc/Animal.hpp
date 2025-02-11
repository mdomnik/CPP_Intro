/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:39:23 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/06 16:58:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string type;
	
	public:
		Animal(void); //default constructor
		// Animal(std::string name); //name constructor
		Animal(const Animal &other); //copy constructor
		Animal & operator = (const Animal &other); //copy assignment constructor
		~Animal(void); //deconstructor

		void makeSound(void) const;
};

#endif