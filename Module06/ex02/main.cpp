#include "./inc/Base.hpp"
#include <cstdlib>   // rand, srand
#include <ctime>     // time

int	main() {
	Base* base = new Base();
	Base* random;

	srand(time(NULL));
	random = base->generate();
	base->identify(*random);
	base->identify(random);
	
	delete random;
	delete base;
};