#include "RPN.hpp"

int main(int ac, char** av) {
	if (ac == 2) {
		try {
			Rpn rpn(av[1]);
			rpn.calcul();
		} catch (std::exception& err) {
			std::cout << err.what() << std::endl;
		}
	}
}