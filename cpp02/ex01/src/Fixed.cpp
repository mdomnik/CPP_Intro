/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:43:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/11 14:50:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Default constructor initializes fixed-point number to 0
Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
//Int constructor; converts int to fixed-point representation (shifts i by _fracBits bits(8); this 8 bit shift, scores the int as (i * 2^_fracBits))
Fixed::Fixed(const int i) : _value(i << _fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}
//Float constructor; convers float to fixed-point representation; (f * 2^_fracBits) rounded to the nearest int
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(f * (1 << _fracBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed & Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//getter
int Fixed::getRawBits(void) const
{
	return _value;
}

//setter
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

//fixed point to float; _value / 2^_fracBits typecasted to float
float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fracBits));
}

//fixed point to int; discards fractional part, converts to int; _value / 2^_fracBits
int Fixed::toInt(void) const
{
	return _value >> _fracBits; // Right shift to get integer part
}

//overload for (<<) insertion of floating-point representation of the fixed point number into the output stream passed as a parameter
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}