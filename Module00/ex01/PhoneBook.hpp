/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:40:10 by kclaudan          #+#    #+#             */
/*   Updated: 2025/11/13 16:52:12 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define	PHONEBOOK_HPP

#include "Contact.hpp"  // Inclut automatiquement Contact.hpp
#include <iostream>        // Pour std::cout
#include <iomanip>         // Pour std::setw

class PhoneBook {
	private:
		Contact	_contacts[8];
		int			_count;
		int			_insertIndex;
	
	public:
		PhoneBook();

		void	addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
		void	truncateAndReplace(std::string &str);
		void	printContacts();
		void	printContactById(int id);
};

#endif