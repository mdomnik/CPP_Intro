/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:56:29 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/30 00:05:25 by mdomnik          ###   ########.fr       */
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
	
	std::cout << "----Creating Contact-----\n";
	saveData("First Name: ", contact.firstName);
	saveData("Last Name: ", contact.lastName);
	saveData("Nickname: ", contact.nickname);
	saveData("Phone number: ", contact.phoneNumber);
	saveData("Darkest secret: ", contact.darkestSecret);
	std::cout << "-----Contact Saved!-----\n";
	return (contact);
}