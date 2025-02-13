/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:46:01 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 02:33:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void); //default constructor
		Ice(const Ice &other); //copy constructor
		Ice & operator = (const Ice &other); //copy assignment constructor
		~Ice(void); //deconstructor

		Ice* clone() const;
		void use(ICharacter &target);
};

#endif