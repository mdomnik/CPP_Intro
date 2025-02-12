/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:53:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:05:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void); //default constructor
		WrongCat(const WrongCat &other); //copy constructor
		WrongCat & operator = (const WrongCat &other); //copy assignment constructor
		~WrongCat(void); //deconstructor
	
		void makeSound(void) const;
};

#endif