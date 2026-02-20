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
	std::cout << std::endl;
	std::cout << std::endl;
	// ----------- Copy ctor case -----------
	try {
		Bureaucrat	kyks("kyks", 42);
		Form				form01("impots01", 50, 45);

		kyks.signForm(form01);
		std::cout << form01 << std::endl;

		Form				form02(form01);
		std::cout << form02 << std::endl;
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown exception caught\n";
	};
	std::cout << std::endl;
	std::cout << std::endl;
	// ----------- Assignement case -----------
	try {
		Bureaucrat	kyks("kyks", 42);
		Form				form01("impots01", 50, 45);
		Form				form02("impots02", 10, 45);

		kyks.signForm(form01);
		std::cout << form01 << std::endl;
		std::cout << form02 << std::endl;
		form02 = form01;
		std::cout << form02 << std::endl;
		kyks.signForm(form02);
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown exception caught\n";
	};
}