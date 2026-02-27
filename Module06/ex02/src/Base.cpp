#include "../inc/Base.hpp"
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include "../inc/../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <typeinfo>

Base::Base() {
	std::cout << "[Base] ctor called\n";
};

Base::Base(const Base& src) {
	std::cout << "[Base] cpy ctor called\n";
	*this = src;
};

Base& Base::operator=(const Base& src) {
	if (this == &src)	return *this;
	std::cout << "[Base] assignement called\n";	
	return *this;
};

Base::~Base() {
	std::cout << "[Base] dtor called\n";
};

int	Base::randomNbrInRange(int min, int max) {
	return min + (std::rand() % (max - min + 1));
};

Base*	Base::generate(void) {
	int randomNbr = randomNbrInRange(0, 2);

	switch(randomNbr) {
		case 0:
		 return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			std::cout << "Error: Type not found" << std::endl;
			return NULL;
	}
};

void	Base::identify(Base* p) {
	std::cout << typeid(*p).name() << std::endl;
};

void	Base::identify(Base& p) {
	std::cout << typeid(p).name() << std::endl;
};
