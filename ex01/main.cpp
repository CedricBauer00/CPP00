/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:23:19 by cbauer            #+#    #+#             */
/*   Updated: 2025/06/30 12:16:43 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
			phoneBook.displayContacts();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command.\n";
	}
	return (0);
}
