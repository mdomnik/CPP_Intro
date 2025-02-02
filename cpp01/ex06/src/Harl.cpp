/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:55:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/02 02:56:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
		typedef void (Harl::*HarlFuncs)();
				
		HarlFuncs functions[4] = { 
		    &Harl::debug, 
		    &Harl::info, 
		    &Harl::warning, 
		    &Harl::error 
		};
				
		std::string levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};
		
		int harlLevel = -1;
		for (int i = 0; i < 4; i++)
		{
			if (levels[i] == level)
				harlLevel = i;
		}

	switch(harlLevel)
	{
		case 0:
			(this->*functions[0])();
			(this->*functions[1])();
			(this->*functions[2])();
			(this->*functions[3])();
			break ;
		case 1:
			(this->*functions[1])();
			(this->*functions[2])();
			(this->*functions[3])();
			break ;
		case 2:
			(this->*functions[2])();
			(this->*functions[3])();
			break ;
		case 3:
			(this->*functions[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}