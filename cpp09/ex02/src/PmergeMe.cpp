/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:11:45 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/11 03:06:55 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <sys/time.h>
#include <set>

//default construcotr
PmergeMe::PmergeMe(void) : _vectorContainer(), _vectorSortTime(0), _dequeContainer(), _dequeSortTime(0) {};

//copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _vectorContainer(other._vectorContainer), _vectorSortTime(other._vectorSortTime), _dequeContainer(other._dequeContainer), _dequeSortTime(other._dequeSortTime) {};

//copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vectorContainer = other._vectorContainer;
		_dequeContainer = other._dequeContainer;
		_vectorSortTime = other._vectorSortTime;
		_dequeSortTime = other._dequeSortTime;
	}
	return *this;
}

//destructor
PmergeMe::~PmergeMe(void) {
	_vectorContainer.clear();
	_dequeContainer.clear();
}

//getter for vector container
std::vector<unsigned int> PmergeMe::getVectorContainer()
{
	return _vectorContainer;
}

//helper function checking for input validity
static unsigned int validateNumber(const std::string& str)
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
}

static void comparePairs(unsigned int a, unsigned int b, unsigned int &small, unsigned int &big)
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

static void binaryInsertionVector(unsigned int element, std::vector<unsigned int> &vc)
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

static std::vector<unsigned int> sortVector(std::vector<unsigned int> vc)
{
	if (vc.size() <= 1)
		return (vc);

	std::vector<unsigned int> largeContainer, smallContainer;
	unsigned int largeNum, smallNum, leftover;

	for (size_t i = 0; i + 1 < vc.size(); i += 2)
	{
		comparePairs(vc[i], vc[i + 1], smallNum, largeNum);
		smallContainer.push_back(smallNum);
		largeContainer.push_back(largeNum);
	}
	
	if (vc.size() % 2 == 1)
		leftover = vc.back();
	
	std::vector<unsigned int> sortedContainer = sortVector(largeContainer);
	while (smallContainer.size() > 0)
	{
		binaryInsertionVector(smallContainer.back(), sortedContainer);
		smallContainer.pop_back();
	}
	if (vc.size() % 2 == 1)
		binaryInsertionVector(leftover, sortedContainer);
	return (sortedContainer);
}


void PmergeMe::sortVectorContainer()
{
	//measure time taken to sort the vector
	_vectorContainer = sortVector(_vectorContainer);
	//end time measurement
}


//printVector function
void PmergeMe::printVector() const
{
	std::cout << "vector: ";
	for (std::vector<unsigned int>::const_iterator i = _vectorContainer.begin(); i != _vectorContainer.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "time: " << _vectorSortTime << std::endl;
}

//printDeque function
void PmergeMe::printDeque() const
{
	std::cout << "deque: ";
	for (std::deque<unsigned int>::const_iterator i = _dequeContainer.begin(); i != _dequeContainer.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}