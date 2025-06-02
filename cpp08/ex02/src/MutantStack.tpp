/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:08:04 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/02 20:28:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <iostream>

// Default constructor
template <typename T>
MutantStack<T>::MutantStack() {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack(void) {
	std::cout << "Destructor called" << std::endl;
}

