/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:56:55 by kclaudan          #+#    #+#             */
/*   Updated: 2025/11/13 17:53:02 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
	
PhoneBook::PhoneBook() : _count(0), _insertIndex(0) {}

void	PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	if (_insertIndex == 2)
		_insertIndex = 0;
	_contacts[_insertIndex].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	if (_insertIndex < 2)
		_insertIndex++;
}

void	PhoneBook::truncateAndReplace(std::string &str) {
	if (str.length() > 10) {
		str.resize(10 - 1);
		str += ".";
	};
}	

void	PhoneBook::printContacts() {
	std::string separator = "+----------+----------+----------+----------+\n";
	std::cout << separator
				<< std::right
				<< "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nick Name"
				<< "|\n" << separator;
	for (int id = 0; _contacts[id].isContactExist() and id < 2; id++)
	{
		std::string firstname = _contacts[id].getFirstName();
		truncateAndReplace(firstname);
		std::string lastname = _contacts[id].getLastName();
		truncateAndReplace(lastname);
		std::string nickname = _contacts[id].getNickName();
		truncateAndReplace(nickname);
		std::cout << "|" << std::setw(10) << id
							<< "|" << std::setw(10) << firstname
							<< "|" << std::setw(10) << lastname
							<< "|" << std::setw(10) << nickname
							<< "|" << std::endl;
		std::cout << separator;
	}
}

void	PhoneBook::printContactById(int id) {
	if (id > 7)
		std::cout << "Index out of range !\n";
	else
	{
		std::string separator = "+----------+----------+----------+----------+\n";
		std::cout << separator
					<< std::right
					<< "|" << std::setw(10) << "Index"
					<< "|" << std::setw(10) << "First Name"
					<< "|" << std::setw(10) << "Last Name"
					<< "|" << std::setw(10) << "Nick Name"
					<< "|\n" << separator;
		if (_contacts[id].isContactExist()){
			std::string firstname = _contacts[id].getFirstName();
			truncateAndReplace(firstname);
			std::string lastname = _contacts[id].getLastName();
			truncateAndReplace(lastname);
			std::string nickname = _contacts[id].getNickName();
			truncateAndReplace(nickname);
			std::cout << "|" << std::setw(10) << id
								<< "|" << std::setw(10) << firstname
								<< "|" << std::setw(10) << lastname
								<< "|" << std::setw(10) << nickname
								<< "|" << std::endl;
			}
		std::cout << separator;
	}
}
