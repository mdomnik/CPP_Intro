/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:11:45 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/11 18:30:48 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <set>
#include <cstdlib>
#include <limits>
#include <ctime>

//default construcotr
PmergeMe::PmergeMe(void) : _vectorContainer(), _dequeContainer() {};

//copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _vectorContainer(other._vectorContainer), _dequeContainer(other._dequeContainer) {};

//copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vectorContainer = other._vectorContainer;
		_dequeContainer = other._dequeContainer;
	}
	return *this;
}

//destructor
PmergeMe::~PmergeMe(void) {
	_vectorContainer.clear();
	_dequeContainer.clear();
}

//helper function checking for input validity
unsigned int PmergeMe::validateNumber(const std::string& str)
{
	if (str.empty())
		throw std::invalid_argument("Empty input");
	
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]))
			throw std::invalid_argument("Invalid character in input: " + str);
	}
	
	std::stringstream stream(str);
	
	unsigned int result;

	stream >> result;

	if (!stream.eof() || stream.fail())
		throw std::invalid_argument("Failed to parse number: " + str);
	if (result > std::numeric_limits<unsigned int>::max())
		throw std::out_of_range("Number out of range: " + str);
	if (result == 0)
		throw std::invalid_argument("Zero is not a positive number");

	return (result);
}

// parse input member function
void PmergeMe::parseInput(char** argv)
{
	unsigned int value;
	
	for (int i = 1; argv[i]; ++i) {
		std::string	arg(argv[i]);
		try
		{
			value = validateNumber(arg);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::exit(EXIT_FAILURE);
		}
		_vectorContainer.push_back(value);
		_dequeContainer.push_back(value);
	}
	printSequenceBefore();
}

void PmergeMe::comparePairs(unsigned int a, unsigned int b, unsigned int &small, unsigned int &big)
{
	if (a > b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}
}

void PmergeMe::binaryInsertionVector(unsigned int element, std::vector<unsigned int> &vc)
{
	size_t low = 0;
	size_t high = vc.size();

	while (low < high)
	{
		size_t mid = (low + high) / 2;
		if (element < vc[mid])
			high = mid;
		else
			low = mid + 1;
	}
	vc.insert(vc.begin() + low, element);
}

void PmergeMe::binaryInsertionDeque(unsigned int element, std::deque<unsigned int> &dc)
{
	size_t low = 0;
	size_t high = dc.size();

	while (low < high)
	{
		size_t mid = (low + high) / 2;
		if (element < dc[mid])
			high = mid;
		else
			low = mid + 1;
	}
	dc.insert(dc.begin() + low, element);
}

std::vector<size_t> PmergeMe::JacobsthalNumsVector(size_t n)
{
	std::set<size_t> uniqueNums;
	std::vector<size_t> j;
	if (n > 0)
		j.push_back(0);
	if (n > 1)
		j.push_back(1);
	while (j.size() >= 2)
	{
		size_t value = j[j.size() - 1] + 2 * j[j.size() - 2];
		if (value >= n)
			break;
		j.push_back(value);
	}	
	for (size_t k = 1; k < j.size(); ++k)
		uniqueNums.insert(j[k]);
	for (size_t k = 0; k < n; ++k)
		uniqueNums.insert(k);
	return (std::vector<size_t>(uniqueNums.begin(), uniqueNums.end()));
}

std::deque<size_t> PmergeMe::JacobsthalNumsDeque(size_t n)
{
	std::set<size_t> uniqueNums;
	std::deque<size_t> j;
	if (n > 0)
		j.push_back(0);
	if (n > 1)
		j.push_back(1);
	while (j.size() >= 2)
	{
		size_t value = j[j.size() - 1] + 2 * j[j.size() - 2];
		if (value >= n)
			break;
		j.push_back(value);
	}	
	for (size_t k = 1; k < j.size(); ++k)
		uniqueNums.insert(j[k]);
	for (size_t k = 0; k < n; ++k)
		uniqueNums.insert(k);
	return (std::deque<size_t>(uniqueNums.begin(), uniqueNums.end()));
}

std::vector<unsigned int> PmergeMe::sortVector(std::vector<unsigned int> vc)
{
	if (vc.size() <= 1)
		return (vc);

	std::vector<unsigned int> largeContainer, smallContainer;
	unsigned int largeNum, smallNum;
	bool hasLeftover = (vc.size() % 2 == 1);
	unsigned int leftover = hasLeftover ? vc.back() : 0;
	for (size_t i = 0; i + 1 < vc.size(); i += 2)
	{
		comparePairs(vc[i], vc[i + 1], smallNum, largeNum);
		smallContainer.push_back(smallNum);
		largeContainer.push_back(largeNum);
	}
	std::vector<unsigned int> sortedContainer = sortVector(largeContainer);
	std::vector<size_t> order = JacobsthalNumsVector(smallContainer.size());
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); ++it)
		binaryInsertionVector(smallContainer[*it], sortedContainer);
	if (hasLeftover)
		binaryInsertionVector(leftover, sortedContainer);
	return (sortedContainer);
}

std::deque<unsigned int> PmergeMe::sortDeque(std::deque<unsigned int> vc)
{
	if (vc.size() <= 1)
		return (vc);

	std::deque<unsigned int> largeContainer, smallContainer;
	unsigned int largeNum, smallNum;
	bool hasLeftover = (vc.size() % 2 == 1);
	unsigned int leftover = hasLeftover ? vc.back() : 0;
	for (size_t i = 0; i + 1 < vc.size(); i += 2)
	{
		comparePairs(vc[i], vc[i + 1], smallNum, largeNum);
		smallContainer.push_back(smallNum);
		largeContainer.push_back(largeNum);
	}
	std::deque<unsigned int> sortedContainer = sortDeque(largeContainer);
	std::deque<size_t> order = JacobsthalNumsDeque(smallContainer.size());
	for (std::deque<size_t>::iterator it = order.begin(); it != order.end(); ++it)
		binaryInsertionDeque(smallContainer[*it], sortedContainer);
	if (hasLeftover)
		binaryInsertionDeque(leftover, sortedContainer);
	return (sortedContainer);
}


void PmergeMe::sortVectorContainer()
{
	clock_t start, end;
	start = clock();
	_vectorContainer = sortVector(_vectorContainer);
	end = clock();
	printSequenceAfter();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vectorContainer.size()
			  << " elements with std::vector : "
			  << std::fixed << std::setprecision(5)
			  << duration << " us" << std::endl;

}

void PmergeMe::sortDequeContainer()
{
	clock_t start, end;
	start = clock();
	_dequeContainer = sortDeque(_dequeContainer);
	end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _dequeContainer.size()
			  << " elements with std::deque : "
			  << std::fixed << std::setprecision(5)
			  << duration << " us" << std::endl;
}


//printVector function
void PmergeMe::printSequenceBefore() const
{
	std::cout << "Before: ";
	for (std::vector<unsigned int>::const_iterator i = _vectorContainer.begin(); i != _vectorContainer.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

//printDeque function
void PmergeMe::printSequenceAfter() const
{
	std::cout << "After: ";
	for (std::vector<unsigned int>::const_iterator i = _vectorContainer.begin(); i != _vectorContainer.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

//wrapper function
void PmergeMe::performSort(char **argv)
{
	parseInput(argv);
	sortVectorContainer();
	sortDequeContainer();
}