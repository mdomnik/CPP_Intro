/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:34:42 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/04 17:03:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"
#include <iostream>
#include <cctype>

//default constructor
RPN::RPN() {}

//copy constructor
RPN::RPN(const RPN &other) : _operands(other._operands) {}

//copy assignment operator
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_operands = other._operands;
	}
	return *this;
}

//destructor
RPN::~RPN() {}

static bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

static int CheckValidChar(const char& c)
{
	unsigned char u = static_cast<unsigned char>(c);

	if (std::isspace(u))
		return (0);
	if (std::isdigit(u))
		return (1);
	if (isOperator(u))
		return (2);
	return (3);
}

bool RPN::ApplyOperator(const char& c)
{
	std::string operators = "+-/*";

	if (_operands.size() < 2)
		return (false);
	int first = _operands.top();
	_operands.pop();
	int second = _operands.top();
	_operands.pop();

	size_t occurence = operators.find(c);
	switch (occurence)
	{
		case 0: // +
			_operands.push(second + first);
			break;
		case 1: // -
			_operands.push(second - first);
			break;
		case 2: // /
			if (first == 0) {
				std::cerr << "Division by zero error" << std::endl;
				return (false);
			}
			_operands.push(second / first);
			break;
		case 3: // *
			_operands.push(second * first);
			break;
		default:
			return (false);
	}
	return (true);
}

//member function: process
void RPN::process(const std::string& input)
{
	for (std::string::const_iterator i = input.begin(); i != input.end(); ++i)
	{
		int type = CheckValidChar(*i);

		switch (type)
		{
			case 1:
				_operands.push(*i - '0');
				break;
			case 2:
				if (ApplyOperator(*i) == false) {
					std::cerr << "Error" << std::endl;
					return;
				}
				break;
			case 3:
				std::cerr << "Error" << std::endl;
				return;
			default:
				break;
		}
	}
	if (_operands.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	else
	{
		std::cout << _operands.top() << std::endl;	
	}
}