/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:11:33 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/11 03:05:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Usage: ./PmergeMe <unsigned int> ... <unsigned int>." << std::endl;
		return (1);
	}
	PmergeMe merge;

	merge.parseInput(argv);
	merge.printVector();
	merge.sortVectorContainer();
	merge.printVector();
}