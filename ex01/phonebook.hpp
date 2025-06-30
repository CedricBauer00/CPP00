/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:59:40 by cbauer            #+#    #+#             */
/*   Updated: 2025/06/30 11:33:42 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contactCount;
		int		replaceIndex;
	public:
		PhoneBook();
		void	addContact();
		void	displayContacts() const;
		void	displaySingle(int index) const;
		int		checkInput();
};

#endif
