/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:57:12 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/31 19:45:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

static void PrintCat(std::string s)
{
	char str[11] = "          ";

	if (s.length() > 9)
	{
		for (int i = 0; i < 9; i++)
			str[i] = s[i];
		str[9] = '.';
		str[10] = '\0';
	}
	else
	{
		for (int i = 0; i < (int)s.length(); i++)
			str[(10 - s.length()) + i] = s[i];
	}
	std::cout << str;
}

static void PrintContactInfo(ContactList::Contact contact)
{
	PrintCat(contact.getInfo(FIRST));
	std::cout << " | ";
	PrintCat(contact.getInfo(LAST));
	std::cout << " | ";
	PrintCat(contact.getInfo(NICKNAME));
}

static void PrintFullContact(ContactList::Contact contact)
{
	std::cout << "\n-----Contact_info-----\n";
	std::cout << "First Name: " << contact.getInfo(FIRST) << std::endl;
	std::cout << "Last Name: " << contact.getInfo(LAST) << std::endl;
	std::cout << "Nickname: " << contact.getInfo(NICKNAME) << std::endl;
	std::cout << "Phone Number: " << contact.getInfo(PHONE) << std::endl;
	std::cout << "Darkest Secret: " << contact.getInfo(SECRET) << std::endl;
	std::cout << "----------------------\n";
}

static void ChooseContact(ContactList::Phonebook phonebook)
{
	std::cout << "Enter index of contact to display: ";
	std::string s;
	getline(std::cin, s);
	if (s.length() > 1 || s[0] < '0' || s[0] > '7')
	{
		std::cout << "Index number out of range. Try Again...\n";
		ChooseContact(phonebook);
		return ;
	}
	int i = s[0] - 48;
	if (phonebook.contact[i].getInfo(FIRST).empty() == 1)
	{
		std::cout << "Index number out of range. Try Again...\n";
		ChooseContact(phonebook);
		return ;
	}
	PrintFullContact(phonebook.contact[i]);
	return ;
}

void SearchContacts(ContactList::Phonebook phoneBook)
{
	ContactList::Contact contact;
	
	if (phoneBook.contact[0].getInfo(FIRST).empty() == 1)
	{
		std::cout << "No Contacts saved in the phonebook...\n";
		return ;
	}
	std::cout << "-----Displaying Contact List-----\n";
	std::cout << "     Index | First_Name |  Last_Name |   Nickname\n";
	for (int i = 0; i < 8; i++)
	{
		contact = phoneBook.contact[i];
		if (contact.getInfo(FIRST).empty() == 1)
			break;
		std::cout << "       [" << i << "]" << " | ";
		PrintContactInfo(contact);
		std::cout << std::endl;
	}
	ChooseContact(phoneBook);
}
