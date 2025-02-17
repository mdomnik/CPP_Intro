/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:40:55 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 21:46:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void); //default constructor
		Dog(const Dog &other); //copy constructor
		Dog & operator = (const Dog &other); //copy assignment constructor
		~Dog(void); //deconstructor
	
		void makeSound(void) const;
};

#endif