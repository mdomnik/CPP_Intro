/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:15:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/30 14:29:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

int main(void)
{
	std::string command;

	ContactList::Phonebook phoneBook;
	int	i = 0;
	std::cout << "-----Welcome to the Phonebook!-----\n";
	do
	{
		std::cout << "Enter Command [ADD/SEARCH/EXIT]: ";
		getline(std::cin, command);
		if (command.compare("ADD") == 0)
		{
			if (i >= 8)
				i = 0;
			phoneBook.contact[i] = AddContact();
			i++;
		}
		if (command.compare("SEARCH") == 0)
		{
			SearchContacts(phoneBook);
			continue;
		}
	} while (command != "EXIT");
	std::cout << "Erasing Phonebook data, bye!\n";
	return (0);
}