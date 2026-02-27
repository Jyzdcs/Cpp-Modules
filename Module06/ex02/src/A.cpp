#include "../inc/A.hpp"

A::A() : Base() {
	std::cout << "[A] ctor called\n";
};

A::A(const A& src) : Base() {
	std::cout << "[A] cpy ctor called\n";
	*this = src;
};

A& A::operator=(const A& src){
	std::cout << "[A] assignement called\n";
	if (this == &src)	return *this;
	return *this;
};

A::~A(){
	std::cout << "[A] dtor called\n";
};
