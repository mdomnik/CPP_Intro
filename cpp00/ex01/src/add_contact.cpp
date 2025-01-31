/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:56:29 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/31 19:43:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

static void saveData(std::string message, std::string& datapoint)
{
	std::cout << message;
	getline(std::cin, datapoint);
	if (datapoint[0] == '\0')
	{
		saveData(message, datapoint);
		return ;
	}
	return ;
}

ContactList::Contact AddContact(void)
{
	ContactList::Contact contact;
	std::string s;

	std::cout << "----Creating Contact-----\n";
	saveData("First Name: ", s);
	contact.setInfo(s, FIRST);
	saveData("Last Name: ", s);
	contact.setInfo(s, LAST);
	saveData("Nickname: ", s);
	contact.setInfo(s, NICKNAME);
	saveData("Phone number: ", s);
	contact.setInfo(s, PHONE);
	saveData("Darkest secret: ", s);
	contact.setInfo(s, SECRET);
	std::cout << "-----Contact Saved!-----\n";
	return (contact);
}