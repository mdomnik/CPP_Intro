/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:45:34 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 02:32:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void); //default constructor
		Cure(const Cure&other); //copy constructor
		Cure & operator = (const Cure &other); //copy assignment constructor
		~Cure(void); //deconstructor

		Cure* clone() const;
		void use(ICharacter &target);
};

#endif
