/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:34:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/04 16:57:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int>_operands;
		bool ApplyOperator(const char& c);
	public:
		//orthodox form
		RPN(); //default constructor
		RPN(const RPN &other); //copy constructor
		RPN &operator=(const RPN &other); //copy assignment operator
		~RPN(); //destructor

		//member functions
		void process(const std::string& input);
};

#endif