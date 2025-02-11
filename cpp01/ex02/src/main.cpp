/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/30 15:17:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string& ref = str;

	std::cout <<  "address_string: " << &str << std::endl;
	std::cout << "address_stringPTR: " << ptr << std::endl;
	std::cout << "address_stringREF: " << &ref << std::endl;

	std::cout <<  "string: " <<  str << std::endl;
	std::cout <<  "stringPTR: " <<  *ptr << std::endl;
	std::cout <<  "stringREF: " <<  ref << std::endl;

	return (0);
}