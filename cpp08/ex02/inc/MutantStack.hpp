/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:08:15 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/02 20:28:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		//constructors
		MutantStack(); // Default constructor
		MutantStack(const MutantStack &other); // Copy constructor
		MutantStack & operator = (const MutantStack &other); // Copy assignment operator
		~MutantStack(void); // Destructor

		//references to function members
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		//new iterator member funtions
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
	
		const_iterator begin() const {return this->c.begin();}
		const_iterator end() const {return this->c.end();}
};

#include "../src/MutantStack.tpp"

#endif