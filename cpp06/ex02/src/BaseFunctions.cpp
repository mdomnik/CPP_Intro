/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:41:05 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/09 20:07:50 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <iostream>
#include <cstdlib>

Base *generate()
{
	int randomNum = rand() % 3;

	switch (randomNum)
	{
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
		default:
			std::cerr << "Random seeding failed" << std::endl;
			break;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "it is A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "it is B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "it is C" << std::endl;
}

void identify(Base& p)
{

	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "it is A" << std::endl;
		return;
	}
	catch(const std::exception& e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "it is B" << std::endl;
		return;
	}
	catch(const std::exception& e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "it is C" << std::endl;
		return;
	}
	catch(const std::exception& e) {}
}
