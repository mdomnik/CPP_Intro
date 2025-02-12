/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:41:31 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 22:58:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void); //default constructor
		Cat(const Cat &other); //copy constructor
		Cat & operator = (const Cat &other); //copy assignment constructor
		~Cat(void); //deconstructor
	
		void makeSound(void) const;
};

#endif