/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:24:58 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/12 23:54:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"
#include <iostream>

// Default Constructor
Brain::Brain(void)
{
	std::cout << "Brain" << " is created! (Default constructor)" << std::endl;
}

// Copy Constructor
Brain::Brain(const Brain &other) : ideas(other.ideas)
{
	std::cout << "Brain" << " is copied! (Copy constructor)" << std::endl;
}

// Copy Assignment Operator
Brain & Brain::operator=(const Brain &other)
{
	if (this != &other)
		ideas[0] = other.ideas[0];
	std::cout << "Brain" << " is assigned! (Copy assignment constructor)" << std::endl;
	return *this;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain" << " is destroyed! (Destructor)" << std::endl;
}

//getter
std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (ideas[i]);
	return("Idea out of scope");
}

//setter
void Brain::setIdea(int i, const std::string &str)
{
	if (i >= 0 && i < 100)
		ideas[i] = str;
}
