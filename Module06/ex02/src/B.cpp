#include "../inc/B.hpp"

B::B() : Base() {
	std::cout << "[B] ctor called\n";
};

B::B(const B& src) : Base() {
	std::cout << "[B] cpy ctor called\n";
	*this = src;
};

B& B::operator=(const B& src){
	std::cout << "[B] assignement called\n";
	if (this == &src)	return *this;
	return *this;
};

B::~B(){
	std::cout << "[B] dtor called\n";
};
