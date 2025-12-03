#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sstream>

void	add_contact(std::string &firstName, std::string &lastName, std::string &nickName, std::string &phoneNumber, std::string &secret)
{
	while (firstName.empty())
	{
		std::cout << "Entrez votre firstName: ";
		std::getline(std::cin, firstName);
		if (firstName.empty()) {
			std::system("clear");
			sleep(1);
			std::cout << "Le champs doit etre rempli !\n";
		}
	}
	while (lastName.empty())
	{
		std::cout << "Entrez votre lastName: ";
		std::getline(std::cin, lastName);
		if (lastName.empty()) {
			std::system("clear");
			sleep(1);
			std::cout << "Le champs doit etre rempli !\n";
		}
	}
	while (nickName.empty())
	{
		std::cout << "Entrez votre nickName: ";
		std::getline(std::cin, nickName);
		if (nickName.empty()) {
			std::system("clear");
			sleep(1);
			std::cout << "Le champs doit etre rempli !\n";
		}
	}
	while (phoneNumber.empty())
	{
		std::cout << "Entrez votre phoneNumber: ";
		std::getline(std::cin, phoneNumber);
		if (phoneNumber.empty()) {
			std::system("clear");
			sleep(1);
			std::cout << "Le champs doit etre rempli !\n";
		}
		else {

		}
	}
	while (secret.empty())
	{
		std::cout << "Entrez votre secret: ";
		std::getline(std::cin, secret);
		if (secret.empty()) {
			std::system("clear");
			sleep(1);
			std::cout << "Le champs doit etre rempli !\n";
		}
	}
}

int main(void)
{
	std::string	input;
	int			index;
	PhoneBook	phoneBook;

	while (input != "EXIT")
	{
		std::cout << "Type one of theses cmd: ADD | SEARCH | EXIT: ";
		std::cin >> input;
		std::cin.ignore();

		if (input == "ADD")
		{
			std::string	firstName;
			std::string	lastName;
			std::string	nickName;
			std::string	phoneNumber;
			std::string	secret;
		
			add_contact(firstName, lastName, nickName, phoneNumber, secret);
			phoneBook.addContact(firstName, lastName, nickName, phoneNumber, secret);
			firstName = "";
			lastName = "";
			nickName = "";
			phoneNumber = "";
			secret = "";

		}
		else if (input == "SEARCH")
		{
			phoneBook.printContacts();
			std::cout << "Type your id: ";
			std::getline(std::cin, input);
			
			index = std::atoi(input.c_str());
			if (index < 0 || index > 7) {
				std::cout << "Index is out of range !\n";
			} else {
				phoneBook.printContactById(index);
			}
		}
	}
}
