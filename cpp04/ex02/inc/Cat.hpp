/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:41:31 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 01:03:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat(void); //default constructor
		Cat(const Cat &other); //copy constructor
		Cat & operator = (const Cat &other); //copy assignment constructor
		~Cat(void); //deconstructor
	
		std::string getIdea(int index) const;
		void setIdea(int index, const std::string& idea);

		void makeSound(void) const;
	};

#endif