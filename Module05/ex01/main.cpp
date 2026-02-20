#include "Bureaucrat.hpp"

int main() {

	// ----------- Normal case -----------
	try {
		Bureaucrat	kyks("kyks", 42);
		Form				form01("impots", 50, 45);

		kyks.signForm(form01);
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	};
	std::cout << std::endl;
	std::cout << std::endl;
	// ----------- Grade too low to sign case -----------
	try {
		Bureaucrat	kyks("kyks", 142);
		Form				form01("impots", 50, 45);

		kyks.signForm(form01);
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown exception caught\n";
	};
}