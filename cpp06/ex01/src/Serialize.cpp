/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:40:47 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 21:46:54 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialize.hpp"
#include <iostream>

// Default constructor
Serializer::Serializer()
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
	(void)other;
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	std::cout << "Assignment operator called" << std::endl;
	return (*this);
}

// Destructor
Serializer::~Serializer()
{
	std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
