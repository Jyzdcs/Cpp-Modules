#include "../inc/Base.hpp"
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include "../inc/../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

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
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "T'es chelou toi !" << std::endl;
	}  
};

void	Base::identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (...) {
		try {
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (...) { 
			try {
				dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::exception& err) {
				std::cout << err.what() << std::endl;
			}
		}
	};
};
