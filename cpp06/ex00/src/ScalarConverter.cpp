/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:15:05 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 21:45:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include "../inc/caseHandling.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

// Default constructor
ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}
// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "Assignment operator called" << std::endl;
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

static t_literalType detectType(const std::string &literal)
{
	// Check for empty string
	if (literal.empty())
		return (UNKNOWN_TYPE);

	//pseudoLiteral detection
	if (findPseudo(literal) != -1)
		return (PSEUDO_TYPE);

	//char detection
	if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return (CHAR_TYPE);

	//int detection
	char *remainInt = NULL;
	long intCheck = std::strtol(literal.c_str(), &remainInt, 10);
	if (*remainInt == '\0' && intCheck >= std::numeric_limits<int>::min() && intCheck <= std::numeric_limits<int>::max())
		return (INT_TYPE);
	
	//float detection
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f') {
		std::string numeral = literal.substr(0, literal.length() - 1);
		if (checkFloatingPointNumberValid(numeral, true))
			return (FLOAT_TYPE);
	}

	//double detection
	if (checkFloatingPointNumberValid(literal, false))
		return (DOUBLE_TYPE);

	//not a valid type
	return (UNKNOWN_TYPE);
}

// Convert function
void ScalarConverter::convert(const std::string &literal)
{

	t_literalType type = detectType(literal);
	
	switch (type)
	{
		case CHAR_TYPE:
			handleChar(literal[0]);
			break;
		case INT_TYPE:
			handleInt(static_cast<int>(std::strtol(literal.c_str(), NULL, 10)));
			break;
		case FLOAT_TYPE:
			handleFloat(std::strtof(literal.c_str(), NULL));
			break;
		case DOUBLE_TYPE:
			handleDouble(std::strtod(literal.c_str(), NULL));
			break;
		case PSEUDO_TYPE:
			handlePseudo(literal);
			break;
		default:
			handleUnknown();
			break;
	}
}