/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:49:09 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:02:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		WrongAnimal(void); //default constructor
		WrongAnimal(std::string name); //name constructor
		WrongAnimal(const WrongAnimal &other); //copy constructor
		WrongAnimal & operator = (const WrongAnimal &other); //copy assignment constructor
		~WrongAnimal(void); //deconstructor

		std::string getType(void) const;
		void makeSound(void) const;
};

#endif