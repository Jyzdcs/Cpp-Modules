#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret(""), _init(false) {}

Contact:: Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
	: _firstName(fn), _lastName(ln), _nickName(nn), _phoneNumber(pn), _darkestSecret(ds) {}

void	Contact::Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

void	Contact::setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) {
	_firstName = fn;	
	_lastName = ln;
	_nickName = nn;
	_phoneNumber = pn;
	_darkestSecret = ds;
	_init = true;
}

void	Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

void	Contact::setNickName(std::string nickName) {
	_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	_darkestSecret = darkestSecret;
}

void	Contact::setInit() {
	_init = true;
}

std::string	Contact::getFirstName() const {
	return _firstName;
}

std::string	Contact::getLastName() const {
	return _lastName;
}

std::string	Contact::getNickName() const {
	return _nickName;
}

std::string	Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return _darkestSecret;
}

bool	Contact::isContactExist() const {
	return _init;
}