#include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat kyks("kyks", 3);
		PresidentialPardonForm test("42");

		kyks.signForm(&test);
		kyks.executeForm(test);
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}
}