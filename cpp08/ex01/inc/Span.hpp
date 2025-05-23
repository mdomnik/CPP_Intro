/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:58:01 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/23 16:27:48 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	_container;
	public:
		Span(); // Default constructor
		Span(unsigned int N); // Constructor with size
		Span(const Span &other); // Copy constructor
		Span & operator = (const Span &other); // Copy assignment operator
		~Span(void); // Destructor
		
		//member functions
		void addNumber(int value);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		template <typename T>
		void addMany(T start, T end)
		{
			int range = std::distance(start, end);
		
			if (_container.size() + range > N)
			{
				throw std::length_error("Adding this range would exceed the container's max data capacity");
			}
			_container.insert(_container.end(), start, end);
		}
};

#endif