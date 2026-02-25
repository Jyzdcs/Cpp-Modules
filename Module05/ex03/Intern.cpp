#include "Intern.hpp"

Intern::Intern() {
	std::cout << "[Intern] ctor called\n";
};

Intern::Intern(const Intern &other) {
  std::cout << "[Intern] Copy constructor called." << std::endl;
  (void)other;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "[Intern] Copy assigment operator called." << std::endl;
  (void)other;
  return *this;
}

Intern::~Intern() {
	std::cout << "[Intern] dtor called\n";
};

AForm*	Intern::makeForm(std::string name, std::string target) {
	std::string typesForm[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;

	while (i < 3) {
		if (typesForm[i] == name) break ;
		i++;
	}
	switch (i) {
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			throw FormNotFound();
	}
};

const char*	Intern::FormNotFound::what() const throw() {
	return "Form type not fond\n";
};
