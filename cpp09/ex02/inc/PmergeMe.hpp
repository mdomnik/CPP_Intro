/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:12:03 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/11 03:02:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
	private:
		std::vector<unsigned int> _vectorContainer;
		double _vectorSortTime;

		std::deque<unsigned int> _dequeContainer;
		double _dequeSortTime;

	public:
		//orthodox canonical form
		PmergeMe(); //default constructor
		PmergeMe(const PmergeMe& other); // copy constructor
		PmergeMe &operator=(const PmergeMe& other); //copy assignment operator
		~PmergeMe(); //destructor

		//getters
		std::vector<unsigned int> getVectorContainer();
		
		//member functions
		void parseInput(char **argv);

		void sortVectorContainer();
		//void sortDeque();

		//testing functions
		void printVector() const;
		void printDeque() const;
};

#endif