/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:01:05 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/31 19:40:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

typedef enum e_info
{
	FIRST,
	LAST,
	NICKNAME,
	PHONE,
	SECRET	
}	t_info;

//NAMESPACE AND CLASS
namespace ContactList //namespace to reference 
{
	class Contact //class name
	{
		private:
			std::string	firstName; //can't be referenced
			std::string	lastName;
			std::string	nickname;
			std::string	phoneNumber;
			std::string	darkestSecret;

		public:
			const std::string& getInfo(t_info info) const;
			void setInfo(std::string s, t_info info);
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