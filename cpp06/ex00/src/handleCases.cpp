/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleCases.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:31:46 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/08 22:50:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/caseHandling.hpp"
#include "../inc/ScalarConverter.hpp"

int findPseudo(const std::string &literal)
{
	const std::string float_pseudo[] = {"nanf", "+inff", "-inff"};
	const std::string double_pseudo[] = {"nan", "+inf", "-inf"};
	for (int i = 0; i < 3; i++) { //compares input to pseudocases
		if (literal == float_pseudo[i] || literal == double_pseudo[i]) {
			return (i);
		}
	}
	return (-1);
}

bool checkFloatingPointNumberValid(std::string numeral, bool isFloat)
{
	char *remainFloat = NULL;
	if (isFloat)
		std::strtof(numeral.c_str(), &remainFloat);
	else
		std::strtod(numeral.c_str(), &remainFloat);
	
	return (*remainFloat == '\0');
}

void displayCharFromNum(double d)
{
	std::cout << "char: ";
	if (d != d || d < 0.0 || d >= 127.0)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (std::isprint(d))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non-displayable" << std::endl;
	return ;
}

void handleChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void handleInt(int i)
{
	displayCharFromNum(static_cast<double>(i));
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void handleFloat(float f)
{
	displayCharFromNum(static_cast<double>(f));
	std::cout << "int: ";
	if (f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void handleDouble(double d)
{
	displayCharFromNum(static_cast<double>(d));
	std::cout << "int: ";
	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void handlePseudo(const std::string &literal)
{
	int caseNum = findPseudo(literal);

	switch (caseNum) {
		case 0: // nan / nanf
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break;
		case 1: // +inf / +inff
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			break;
		case 2: // -inf / -inff
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			break;
	}
	return; 
}

void handleUnknown(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
