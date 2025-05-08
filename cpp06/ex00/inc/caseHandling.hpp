/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caseHandling.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:32:47 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/08 20:34:54 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASEHANDLING_HPP
# define CASEHANDLING_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>

typedef enum e_literalType
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	PSEUDO_TYPE,
	UNKNOWN_TYPE
} t_literalType;

int findPseudo(const std::string &literal);
bool checkFloatingPointNumberValid(std::string numeral, bool isFloat);
void displayCharFromNum(double d);

void handleChar(char c);
void handleInt(int i);
void handleFloat(float f);
void handleDouble(double d);
void handlePseudo(const std::string &literal);
void handleUnknown(void);

#endif