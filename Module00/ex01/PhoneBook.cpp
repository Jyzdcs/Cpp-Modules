/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:56:55 by kclaudan          #+#    #+#             */
/*   Updated: 2025/12/03 11:52:55 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
	
PhoneBook::PhoneBook() : _insertIndex(0) {}

void	PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	_contacts[_insertIndex].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	_insertIndex = (_insertIndex + 1) % 8;
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
	for (int id = 0; _contacts[id].isContactExist() and id < 8; id++)
	{
		std::string firstName = _contacts[id].getFirstName();
		truncateAndReplace(firstName);
		std::string lastName = _contacts[id].getLastName();
		truncateAndReplace(lastName);
		std::string nickName = _contacts[id].getNickName();
		truncateAndReplace(nickName);
		std::cout << "|" << std::setw(10) << id
							<< "|" << std::setw(10) << firstName
							<< "|" << std::setw(10) << lastName
							<< "|" << std::setw(10) << nickName
							<< "|" << std::endl;
		std::cout << separator;
	}
}

void	PhoneBook::printContactById(int id) {
	if (id > 7)
		std::cout << "Index out of range !\n";
	else
	{
		std::string separator = "+----------+----------+----------+----------+----------+\n";
		std::cout << separator
					<< std::right
					<< "|" << std::setw(10) << "First Name"
					<< "|" << std::setw(10) << "Last Name"
					<< "|" << std::setw(10) << "Nick Name"
					<< "|" << std::setw(10) << "Phone"
					<< "|" << std::setw(10) << "Secret"
					<< "|\n" << separator;
		if (_contacts[id].isContactExist()){
			std::string firstName = _contacts[id].getFirstName();
			truncateAndReplace(firstName);
			std::string lastName = _contacts[id].getLastName();
			truncateAndReplace(lastName);
			std::string nickName = _contacts[id].getNickName();
			truncateAndReplace(nickName);
			std::string phoneNumber = _contacts[id].getPhoneNumber();
			truncateAndReplace(phoneNumber);
			std::string darkestSecret = _contacts[id].getDarkestSecret();
			truncateAndReplace(darkestSecret);
			std::cout << "|" << std::setw(10) << firstName
								<< "|" << std::setw(10) << lastName
								<< "|" << std::setw(10) << nickName
								<< "|" << std::setw(10) << phoneNumber
								<< "|" << std::setw(10) << darkestSecret
								<< "|" << std::endl;
			}
		std::cout << separator;
	}
}
