/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:58:24 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/23 16:27:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <algorithm>
#include <limits>
#include <iostream>
#include <iterator>
#include <stdexcept>

//default constructor
Span::Span (void) : N(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//constructor with size
Span::Span (unsigned int N) : N(N)
{
	std::cout << "Constructor with size called" << std::endl;
}

//copy constructor
Span::Span (const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->_container = other._container;
	}
	std::cout << "Copy constructor called" << std::endl;
}

//copy assignment operator
Span & Span::operator = (const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->_container = other._container;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

//destructor
Span::~Span (void)
{
	std::cout << "Destructor called" << std::endl;
}

//addNumber
void Span::addNumber(int value)
{
	if (_container.size() >= N)
		throw std::length_error("Container Size Exceeded");
	_container.push_back(value);
}

//shortestSpan
int Span::shortestSpan(void) const
{
	if (_container.size() < 2)
	{
		throw std::runtime_error("Not enough elements to find the shortest span");
	}
	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());

	int min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff == 0)
			return (0);
		if (diff < min)
			min = diff;
	}
	return (min);
}

//LongestSpan
int Span::longestSpan(void) const
{
	if (_container.size() < 2)
	{
		throw std::runtime_error("Not enough elements to find the longest span");
	}
	return (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));
}
