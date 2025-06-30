/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:46:18 by cbauer            #+#    #+#             */
/*   Updated: 2025/06/30 11:23:57 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""),
					lastName(""),
					nickName(""),
					phoneNumber(""),
					darkestSecret("")
					{}

void	Contact::setContact(const std::string& first,
							const std::string& last,
							const std::string& nick,
							const std::string& phone,
							const std::string& secret)
{
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

std::string	shortenString(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void	Contact::displayShort(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << shortenString(firstName);
	std::cout << "|" << std::setw(10) << shortenString(lastName);
	std::cout << "|" << std::setw(10) << shortenString(nickName);
	std::cout << "|" << std::endl;
}

void	Contact::displayFull() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void	Contact::setFirst(const std::string& input)
{
	firstName = input;
}

void	Contact::setLast(const std::string& input)
{
	lastName = input;
}


void	Contact::setNick(const std::string& input)
{
	nickName = input;
}

void	Contact::setNumber(const std::string& input)
{
	phoneNumber = input;
}

void	Contact::setSecret(const std::string& input)
{
	darkestSecret = input;
}
