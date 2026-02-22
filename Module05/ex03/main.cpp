#include "Intern.hpp"

int main() {
	AForm *shrubbery;
	// AForm *robotomy;
	// AForm *presidential;

	try {
		Bureaucrat kyks("pika", 1);
		Intern test;

		shrubbery = test.makeForm("ShrubberyCreationForm", "test");
		kyks.signForm(shrubbery);
		kyks.executeForm(*shrubbery);
		
	}	catch (std::exception& err) {
		std::cout << err.what();
	}
	delete shrubbery;
	// delete robotomy;
	// delete presidential;
}