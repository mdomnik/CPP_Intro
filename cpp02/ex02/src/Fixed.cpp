/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:43:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/04 13:54:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::_fracBits = 8;

// Default constructor initializes fixed-point number to 0
Fixed::Fixed(void) : _value(0) {}

//Int constructor; converts int to fixed-point representation (shifts i by _fracBits bits(8); this 8 bit shift, scores the int as (i * 2^_fracBits))
Fixed::Fixed(const int i) : _value(i << _fracBits) {}

//Float constructor; convers float to fixed-point representation; (f * 2^_fracBits) rounded to the nearest int
Fixed::Fixed(const float f)
{
	_value = (int)(roundf(f * (1 << _fracBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

// Copy assignment operator
Fixed & Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed() {}

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
	return ((_value / (1  << _fracBits)));
}

//overload for (<<) insertion of floating-point representation of the fixed point number into the output stream passed as a parameter
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const //overload greater than operator
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const //overload less than operator
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const //overload greater than or equal operator
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const //overload less than or equal operator
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const //overload is equal operator
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const //overload is not equal operator
{
	return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const //adding 2 fixed values
{
	Fixed result;
	result.setRawBits(_value + other._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const //subtracting 2 fixed values
{
	Fixed result;
	result.setRawBits(_value - other._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const //multiplying 2 fixed values by multiplying them together and then right shift it
{
	Fixed result;
	
	long total = (long)_value * other._value;
	result.setRawBits((int)(total >> _fracBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const //division with 0 check 
{
	Fixed result;
	if (other._value == 0)
	{
		std::cerr << "Error: can't divide by 0" << std::endl;
		result.setRawBits(0);
	}
	else
	{
		long div = (long)(_value) << _fracBits; //_value * 2^_fracBits
		result.setRawBits((int)(div / other._value));
	}
	return (result);
}

Fixed &Fixed::operator++(void) //pre increment
{
	_value++;
	return *this;
}

Fixed &Fixed::operator--(void) //pre decrement
{
	_value--;
	return *this;
}

Fixed Fixed::operator++(int) //post increment
{
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed Fixed::operator--(int) //post increment
{
	Fixed temp(*this);
	_value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) //returns ref to smallest number
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) //returns const ref to smallest number
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) //returns ref to highest number
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) //returns const ref to highest number
{
	if (a > b)
		return a;
	return b;
}
