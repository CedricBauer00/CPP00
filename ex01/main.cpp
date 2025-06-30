/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:23:19 by cbauer            #+#    #+#             */
/*   Updated: 2025/06/28 14:04:06 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			return (0);
		for (size_t i = 0; i < command.length(); ++i)
			if (std::islower(command[i]))
				command[i] = toupper(command[i]);
		if (command == "ADD")
			phoneBook.checkInput();
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			std::cout << "Index to view: ";
			std::string indexStr;
			if (!std::getline(std::cin, indexStr))
				return (0);
			int index = std::atoi(indexStr.c_str());
			phoneBook.displayContact(index);
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command.\n";
	}
	return (0);
}
