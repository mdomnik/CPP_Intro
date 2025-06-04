/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:34:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/04 02:37:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
	private:
	public:
		//orthodox form
		RPN(); //default constructor
		RPN(const RPN &other); //copy constructor
		RPN &operator=(const RPN &other); //copy assignment operator
		~RPN(); //destructor

		//member functions
		void process(const std::string& expression);

}

#endif