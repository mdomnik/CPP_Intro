/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:08:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/02 20:39:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	// Testing MutantStack
	std::cout << "\n\033[1;34m=== MutantStack Test ===\033[0m\n" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;   // Should print 17

	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl; // Should print 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);

	std::cout << "contents:" << std::endl;
	MutantStack<int>::iterator it1 = mstack.begin();
	MutantStack<int>::iterator ite1 = mstack.end();

	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}

	std::stack<int> s(mstack);

	std::cout << "\n\033[1;34m--------------------------\033[0m\n" << std::endl;

	// Testing std::list
	std::cout << "\n\033[1;34m=== std::list Test ===\033[0m\n" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << "top: " << lst.back() << std::endl;      // Should print 17

	lst.pop_back();

	std::cout << "size: " << lst.size() << std::endl;     // Should print 1

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	// [...]
	lst.push_back(0);

	std::cout << "contents:" << std::endl;
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();

	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::list<int> copy(lst);

	std::cout << "\n\033[1;34m--------------------------\033[0m\n" << std::endl;

	return 0;
}
