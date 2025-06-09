/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:11:33 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/09 02:24:58 by mdomnik          ###   ########.fr       */
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
	merge.sortVector(merge.getVectorContainer());
	merge.printDeque();
}