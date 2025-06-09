/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:11:45 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/09 02:26:10 by mdomnik          ###   ########.fr       */
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

static void sortPairs(unsigned int num1, unsigned int num2, unsigned int &small, unsigned int &big)
{
	if (num1 < num2)
	{
		small = num1;
		big = num2;
	}
	else
	{
		small = num2;
		big = num1;
	}
}

static size_t jacobsthalCheck(size_t num)
{
	if (num == 0)
		return (0);
	if (num == 1)
		return (1);
	size_t ret = jacobsthalCheck(num - 1) + 2 * jacobsthalCheck(num - 2);
	return (ret);
		
}

static std::vector<size_t> getJacobsthalNumbers(size_t size)
{
	std::vector<size_t> numbers;
	std::set<size_t> seen;
	size_t i = 1;

	while (1)
	{
		i = jacobsthalCheck(i);
		if (i >= size)
			break;
		if (seen.find(i) == seen.end())
		{
			numbers.push_back(i);
			seen.insert(i);
		}
		i++;
	}
	for (size_t k = 0; k < size; ++k)
	{
		if (seen.find(k) == seen.end())
			numbers.push_back(k);
	}
	return (numbers);
}

static void insertVector(std::vector<unsigned int>& vec, unsigned int value)
{
	size_t left = 0;
	size_t right = vec.size();

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (value < vec[mid])
			right = mid;
		else
			left = mid + 1;
	}
	vec.insert(vec.begin() + left, value);
}

//Sorting Functions for vector container (Ford=Johnson / merge-sort)
std::vector<unsigned int> PmergeMe::sortVector(std::vector<unsigned int> vc)
{
	if (vc.size() <= 1)
		return (vc);
	
	std::vector<unsigned int> pend, mainChain;
	unsigned int small, big;
	
	for (size_t i = 0; i < vc.size() - 1; i += 2)
	{
		sortPairs(vc[i], vc[i + 1], small, big);
		pend.push_back(small);
		mainChain.push_back(big);
	}
	
	bool isremain = vc.size() % 2 == 1;
	unsigned int remain = 0;
	if (isremain)
		remain = vc[vc.size() - 1];
	
	mainChain = sortVector(mainChain);

	std::vector<size_t> jnum = getJacobsthalNumbers(pend.size());
	for (size_t i = 0; i < jnum.size(); ++i)
	{
		size_t index = jnum[i];
		if (index < pend.size())
			insertVector(mainChain, pend[index]);
	}
	
	if (isremain)
		insertVector(mainChain, remain);
	return mainChain;
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