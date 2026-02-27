#include "../inc/C.hpp"

C::C() : Base() {
	std::cout << "[C] ctor called\n";
};

C::C(const C& src) : Base() {
	std::cout << "[C] cpy ctor called\n";
	*this = src;
};

C& C::operator=(const C& src){
	std::cout << "[C] assignement called\n";
	if (this == &src)	return *this;
	return *this;
};

C::~C(){
	std::cout << "[C] dtor called\n";
};
