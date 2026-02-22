#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat kyks("kyks", 13);
		PresidentialPardonForm test("42");

		kyks.signForm(&test);
		kyks.executeForm(test);
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat kyks("kyks", 30);
		RobotomyRequestForm test("42");

		kyks.signForm(&test);
		kyks.executeForm(test);
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat kyks("kyks",145);
		ShrubberyCreationForm test("42");

		kyks.signForm(&test);
		kyks.executeForm(test);
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}
}