/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:42:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/06/02 23:49:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>_exchangerate;
		std::map<std::string, double>_inputDateValue;
	public:
		//orthodox form
		BitcoinExchange(); //default constructor
		BitcoinExchange(const std::string& database); //file constructor
		BitcoinExchange(const BitcoinExchange &other); //copy constructor
		BitcoinExchange &operator=(const BitcoinExchange &other); //copy assignment operator
		~BitcoinExchange(); //destructor

		//member functions
		void LoadDataBase(const std::string& database);
		void ProcessInputFile(const std::string& inputFile);
};

#endif