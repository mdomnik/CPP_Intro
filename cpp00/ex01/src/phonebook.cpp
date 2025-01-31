/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:15:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/31 19:46:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

const std::string& ContactList::Contact::getInfo(t_info info) const
{
	if (info == FIRST)
		return firstName;
	if (info == LAST)
		return lastName;
	if (info == NICKNAME)
		return nickname;
	if (info == PHONE)
		return phoneNumber;
	if (info == SECRET)
		return darkestSecret;
	return NULL;
}

void ContactList::Contact::setInfo(std::string s, t_info info)
{
	if (info == FIRST)
		firstName = s;
	if (info == LAST)
		lastName = s;
	if (info == NICKNAME)
		nickname = s;
	if (info == PHONE)
		phoneNumber = s;
	if (info == SECRET)
		darkestSecret = s;
}


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