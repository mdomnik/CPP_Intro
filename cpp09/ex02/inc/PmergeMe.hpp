/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:12:03 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/11 05:25:06 by mdomnik          ###   ########.fr       */
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
		std::deque<unsigned int> _dequeContainer;

	public:
		//orthodox canonical form
		PmergeMe(); //default constructor
		PmergeMe(const PmergeMe& other); // copy constructor
		PmergeMe &operator=(const PmergeMe& other); //copy assignment operator
		~PmergeMe(); //destructor

		//---member functions---

		//parsing
		unsigned int validateNumber(const std::string& str);
		void parseInput(char **argv);

		//binary search
		void comparePairs(unsigned int a, unsigned int b, unsigned int &small, unsigned int &big);
		void binaryInsertionVector(unsigned int element, std::vector<unsigned int> &vc);
		void binaryInsertionDeque(unsigned int element, std::deque<unsigned int> &dc);

		//Jacobsthal
		std::vector<size_t> JacobsthalNumsVector(size_t n);
		std::deque<size_t> JacobsthalNumsDeque(size_t n);

		//sorting
		std::vector<unsigned int> sortVector(std::vector<unsigned int> vc);
		std::deque<unsigned int> sortDeque(std::deque<unsigned int> vc);
		
		//init sort call
		void sortVectorContainer();
		void sortDequeContainer();

		//printing functions
		void printSequenceBefore() const;
		void printSequenceAfter() const;

		//wrapper
		void performSort(char **argv);
};

#endif