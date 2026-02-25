#include "Intern.hpp"

int main() {
	AForm *shrubbery;
	AForm *robotomy;
	AForm *presidential;
	AForm *unknow;

	try {
		Bureaucrat kyks("pika", 1);
		Intern test;

		shrubbery = test.makeForm("ShrubberyCreationForm", "test");
		kyks.signForm(shrubbery);
		kyks.executeForm(*shrubbery);

	}	catch (std::exception& err) {
		std::cout << err.what();
	}
	std::cout << std::endl;
	try {
		Bureaucrat kyks("pika", 1);
		Intern test;

		robotomy = test.makeForm("RobotomyRequestForm", "test");
		kyks.signForm(robotomy);
		kyks.executeForm(*robotomy);

	}	catch (std::exception& err) {
		std::cout << err.what();
	}
	std::cout << std::endl;
	try {
		Bureaucrat kyks("pika", 1);
		Intern test;

		presidential = test.makeForm("PresidentialPardonForm", "test");
		kyks.signForm(presidential);
		kyks.executeForm(*presidential);

	}	catch (std::exception& err) {
		std::cout << err.what();
	}
	std::cout << std::endl;
	try {
		Bureaucrat kyks("pika", 1);
		Intern test;

		unknow = test.makeForm("unknow", "test");
		kyks.signForm(unknow);
		kyks.executeForm(*unknow);

	}	catch (std::exception& err) {
		std::cout << err.what();
	}
	delete shrubbery;
	delete robotomy;
	delete presidential;
}