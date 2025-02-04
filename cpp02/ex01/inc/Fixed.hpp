/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:44 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/04 12:39:39 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value; //int holding fixed-point representation
		static const int	_fracBits; //constant telling us how many bits are used for fractions (8 bits, meaning a value of 256 (_value / 256))

	public:
		Fixed(void); //default constructor
		Fixed(const int i); //int constructor
		Fixed(const float f); //float constructor
		Fixed(const Fixed &other); //copy constructor
		Fixed & operator = (const Fixed &other); //copy assignment constructor
		~Fixed(void); //deconstructor
		
		int getRawBits(void) const; //getter
		void setRawBits(int const raw); //setter
		
		float toFloat(void) const; //fixed-point to float
		int toInt(void) const; //fixed-point to int
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); //print fixed-point to output stream

#endif