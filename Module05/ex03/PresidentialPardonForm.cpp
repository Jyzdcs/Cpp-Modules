#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
: AForm(name, 25, 5) {
		std::cout << "[PresidentialPardonForm] ctor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
		std::cout << "[PresidentialPardonForm] cpy ctor called\n";
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	if (this == &src) return *this;

	this->setIsSigned(src.getIsSigned());
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[PresidentialPardonForm] dtor called\n";
};

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned()) {
		throw NotSigned();
	} else if (executor.getGrade() > this->getGradeToExec()) {
		throw GradeTooLowException();
	} else {
		std::cout << "Informs that " << executor.getName() << " has been pardoned by Zaphod Beeblebrox\n";
	}
}