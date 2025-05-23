/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:40:55 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 01:03:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
	public:
		Dog(void); //default constructor
		Dog(const Dog &other); //copy constructor
		Dog & operator = (const Dog &other); //copy assignment constructor
		~Dog(void); //deconstructor
	
		std::string getIdea(int index) const;
		void setIdea(int index, const std::string& idea);

		void makeSound(void) const;
};

#endif