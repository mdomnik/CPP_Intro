/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:10:41 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 21:45:34 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter(); // Default constructor
		ScalarConverter(const ScalarConverter &other); // Copy constructor
		ScalarConverter &operator=(const ScalarConverter &other); // Assignment operator
		~ScalarConverter(); // Destructor
	public:
		static void convert(const std::string &literal);
};

#endif