/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:44 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/11 14:42:43 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int _fracBits = 8;

	public:
		Fixed(void); //default constructor
		Fixed(const Fixed &other); //copy constructor
		Fixed & operator = (const Fixed &other); //copy assignment constructor
		~Fixed(void); //deconstructor

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif