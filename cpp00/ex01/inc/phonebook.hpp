/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:01:05 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/30 00:04:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

//NAMESPACE AND CLASS
namespace ContactList //namespace to reference 
{
	class Contact //class name
	{
		public:
			std::string	firstName; //can be referenced
			std::string	lastName;
			std::string	nickname;
			std::string	phoneNumber;
			std::string	darkestSecret;
	};
	class Phonebook
	{
		public:
			Contact contact[8];
	};
} //namespace contactList

// ---FUNCTION DECLERATIONS---
ContactList::Contact AddContact(void);
void SearchContacts(ContactList::Phonebook phoneBook);

#endif