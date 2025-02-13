/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:39:23 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:14:54 by mdomnik          ###   ########.fr       */
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
		Animal(std::string name); //name constructor
		Animal(const Animal &other); //copy constructor
		Animal & operator = (const Animal &other); //copy assignment constructor
		virtual ~Animal(void); //deconstructor

		std::string getType(void) const;
		virtual void makeSound(void) const; //allows runtime polymorthism instead of compile time
};

#endif