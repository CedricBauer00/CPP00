/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:32:13 by cbauer            #+#    #+#             */
/*   Updated: 2025/06/30 13:10:36 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : contactCount(0), replaceIndex(0) {}

void	PhoneBook::addContact()
{
	if (contactCount < 8)
		contactCount++;
	replaceIndex = (replaceIndex + 1) % 8;
}

void	PhoneBook::displayContacts() const
{
	std::string indexStr;

	if (contactCount == 0)
	{
		std::cout << "No contacts found." << std::endl;
		return ;
	}
	std::cout	<< "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nick Name"
				<< "|" << std::endl;
	for (int i = 0; i < contactCount; i++)
	contacts[i].displayShort(i);
	std::cout << "Index to view: ";
	if (!std::getline(std::cin, indexStr))
		return ;
	if (indexStr.size() != 1 || !std::isdigit(indexStr[0]))
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	int index = std::atoi(indexStr.c_str());
	displaySingle(index);
}

void	PhoneBook::displaySingle(int index) const
{
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	contacts[index].displayFull();
}

int	PhoneBook::checkInput()
{
	std::string first;
	std::string last;
	std::string nick;
	std::string number;
	std::string secret;
	std::cout << "First Name: ";
	if (!std::getline(std::cin, first))
		return (-1);
	std::cout << "Last Name: ";
	if (!std::getline(std::cin, last))
		return (-1);
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nick))
		return (-1);
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, number))
		return (-1);
	std::cout << "Darkest Secret: ";
	if (!std::getline(std::cin, secret))
		return (-1);
	std::string array[] = {first, last, nick, number, secret};
	for (int i = 0; i < 5; ++i)
	{
		if (array[i].empty())
			return (-1);
	}
	contacts[replaceIndex].setContact(first, last, nick, number, secret);
	addContact();
	std::cout << "Contact added.\n";
	return (0);
}