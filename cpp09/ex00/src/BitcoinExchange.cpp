/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:43:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/03 02:13:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <string>
#include <cstdlib>

//default constructor
BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor called." << std::endl;
}

//file constructor
BitcoinExchange::BitcoinExchange(const std::string& database)
{
	std::cout << "File constructor called with database: " << database << std::endl;
	LoadDataBase(database);
}

//copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangerate(other._exchangerate)
{
	std::cout << "Copy constructor called." << std::endl;
}

//copy assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other) {
		_exchangerate = other._exchangerate;
	}
	return *this;
}

//destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor called." << std::endl;
}

static std::string TrimWhiteSpace(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return ("");
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return (str.substr(first, last - first + 1));
}

static bool IsValidDateFormat(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); ++i)
	{
		if ((i == 4 || i == 7))
			continue;
		if (!isdigit(date[i]))
			return (false);
	}
	
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	
	static const int daysinEachMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int maxDays = daysinEachMonth[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		maxDays = 29;
	
	if (day < 1 || day > maxDays)
		return (false);

	return (true);
}

static std::map<std::string, double> ParseExchangeRate(const std::string& database)
{
	std::map<std::string, double> exchangeRateTable;

	try {
		std::ifstream file(database.c_str());
		if (!file.is_open())
			throw std::runtime_error("Error: could not open database file. Check the file path again!");

		std::string line;
		std::getline(file, line);
		int lineNumber = 2;

		while (std::getline(file, line))
		{
			std::ostringstream oss;

			size_t commaLoc = line.find(',');
			if (commaLoc == std::string::npos) {
				oss << "Error: Bad format at line " << lineNumber << ": (" << line << ")";
				throw std::runtime_error(oss.str());
			}

			std::string date = TrimWhiteSpace(line.substr(0, commaLoc));
			std::string BTCValue = TrimWhiteSpace(line.substr(commaLoc + 1));

			if (date.empty() || BTCValue.empty()) {
				oss << "Error: Bad format at line " << lineNumber << ": (" << line << ")";
				throw std::runtime_error(oss.str());
			}
			if (!IsValidDateFormat(date)) {			
				oss << "Error: Invalid date format or date at line " << lineNumber << ": (" << date << ")";
				throw std::runtime_error(oss.str());
			}

			double rate;
			char* end;
			rate = std::strtod(BTCValue.c_str(), &end);
			if (*end != '\0') {
				oss << "Error: Invalid rate at line " << lineNumber << ": (" << BTCValue << ")";
				throw std::runtime_error(oss.str());
			}
			if (rate < 0) {
				oss << "Error: Negative rate at line " << lineNumber << ": (" << BTCValue << ")";
				throw std::runtime_error(oss.str());
			}
			if (exchangeRateTable.count(date) > 0) {
				oss << "Error: Duplicate date at line " << lineNumber << ": (" << date << ")";
				throw std::runtime_error(oss.str());
			}

			exchangeRateTable[date] = rate;
			lineNumber++;
		}
	} catch (const std::exception& e) {
		std::cerr << "Could not load database" << std::endl;
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	return (exchangeRateTable);
}

//member function to load the database
void BitcoinExchange::LoadDataBase(const std::string& database)
{
	_exchangerate = ParseExchangeRate(database);
}

//member function to load the input file
void BitcoinExchange::ProcessInputFile(const std::string &inputFile)
{
	try {
		std::ifstream file(inputFile.c_str());
		if (!file.is_open())
			throw std::runtime_error("Error: could not open input file. Check the file path again!");

		std::string line;
		std::getline(file, line);

		while (std::getline(file, line))
		{
			std::ostringstream oss;
			size_t pipeLoc = line.find('|');
			if (pipeLoc == std::string::npos) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			
			std::string date = TrimWhiteSpace(line.substr(0, pipeLoc));
			std::string valueStr = TrimWhiteSpace(line.substr(pipeLoc + 1));

			if (!IsValidDateFormat(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			
			char *end;
			double value = std::strtod(valueStr.c_str(), &end);
			if (*end != '\0') {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			if (value < 0) {
				std::cerr << "Error: not a positive number. " << std::endl;
				continue;
			}
			if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			
			std::map<std::string, double>::const_iterator iterator = _exchangerate.lower_bound(date);
			if (iterator == _exchangerate.end() || iterator->first != date) {
				if (iterator == _exchangerate.begin()) {
					std::cerr << "Error: no data found in the database prior or at your given date." << std::endl;
					continue; 
				}
				--iterator;
			}

			double rate = iterator->second;
			double result = value * rate;
			
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Could not load input file" << std::endl;
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}