/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:42:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/06 17:49:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>

Animal::Animal(void): type("Animal") {
	std::cout << "Animal " << type << " is created! (Default constructor)" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal " << type << " is copied! (Copy constructor)" << std::endl;
}

Animal & Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal " << type << " is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal " << type << " is destroyed! (Destructor)" << std::endl;
}