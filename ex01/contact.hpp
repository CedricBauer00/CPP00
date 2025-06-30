/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:37:38 by cbauer            #+#    #+#             */
/*   Updated: 2025/06/30 11:33:05 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact();
		void	setContact(
			const std::string& first,
			const std::string& last,
			const std::string& nick,
			const std::string& phone,
			const std::string& secret
		);
		void	displayShort(int index) const;
		void	displayFull() const;
		void	setFirst(const std::string& input);
		void	setLast(const std::string& input);
		void	setNick(const std::string& input);
		void	setNumber(const std::string& input);
		void	setSecret(const std::string& input);
};

#endif