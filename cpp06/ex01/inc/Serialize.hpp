/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:36:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 21:46:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer(); // Default constructor
		Serializer(const Serializer &other); // Copy constructor
		Serializer &operator=(const Serializer &other); // Assignment operator
		~Serializer(); // Destructor
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif