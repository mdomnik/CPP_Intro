/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:42:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/12 01:31:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>

// default constructor
template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//constructor with size
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "Constructor with size called" << std::endl;
	if (n > 0)
		_array = new T[n];
	else
		_array = NULL;
}

//copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(other._size)
{
	std::cout << "Copy constructor called" << std::endl;
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}
}

// copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
}

// destructor
template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	delete[] _array;
}

// subscript operator
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _array[i];
}

// const subscript operator
template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _array[i];
}

// size function
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}