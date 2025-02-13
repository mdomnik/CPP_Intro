/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:24:04 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/13 04:25:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

#define FloorSpace 20

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *slot[4];
		static AMateria *materiasDropped[FloorSpace];
		static int		dropped;

	public:
		Character();
		Character(std::string const &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
	
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif