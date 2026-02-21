#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
	: AForm(name, 72, 45) {
		std::cout << "[RobotomyRequestForm] ctor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
		std::cout << "[RobotomyRequestForm] cpy ctor called\n";
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	if (this == &src) return *this;

	
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[RobotomyRequestForm] dtor called\n";
};

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	std::cout << "Frrrrrrrrr Frrrrrrrrr" << std::endl;

	std::srand(time(0));
	if (std::rand() % 2)
		std::cout << executor.getName() << " has been successfully robotomized!\n";
	else
		std::cout << executor.getName() << " failed to robotomy\n";
};