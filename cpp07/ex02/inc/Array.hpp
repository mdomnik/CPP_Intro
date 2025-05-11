/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:41:55 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/12 01:34:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T> class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array(); // Default constructor
		Array(unsigned int n); // Constructor with size
		Array(const Array& other); // Copy constructor
		Array& operator=(const Array& other); // Assignment operator
		~Array(); // Destructor
	
		// element access
		T& operator[](unsigned int i); // Subscript operator
		const T& operator[](unsigned int i) const; // Const subscript operator
	
		// member functions
		unsigned int size() const;
};

#include "../src/Array.tpp"

#endif 