/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:57:31 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 02:45:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

 //Any class containing at least pure virtual function becomes
 // abstract and therefore cannot be instantiated
class AAnimal
{
	protected:
		std::string type;
	
	public:
		AAnimal(void); //default constructor
		AAnimal(const AAnimal &other); //copy constructor
		AAnimal & operator = (const AAnimal &other); //copy assignment constructor
		virtual ~AAnimal(void); //deconstructor

		std::string getType(void) const;
		virtual void makeSound(void) const = 0; //pure virtual function with '= 0' syntax
};

#endif