#include "Data.hpp"

Data::Data() {
	std::cout << "[Data] ctor called\n";	
};

Data::Data(const Data& src) {
	std::cout << "[Data] assignement called\n";	
	*this = src;
};

Data& Data::operator=(const Data& src) {
	if (this == &src)	return *this;
	std::cout << "[Data] assignement called\n";	
	return *this;
};

Data::~Data() {
	std::cout << "[Data] dtor called\n";	
};

std::string	Data::getData() {
	return _data;
};

void				Data::setData(std::string data) {
	_data = data;
};