#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade > 150) throw GradeTooLowException();
	if (grade < 1) throw GradeTooHighException();
	std::cout << "[Bureaucrat] constructor called\n";
};

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {
	std::cout << "[Bureaucrat] copy constructor called\n";
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this == &src)	return *this;

	this->_grade = src._grade;
	return *this;
};

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat] destructor called\n";
};

const std::string	Bureaucrat::getName() const {
	return (_name);
};

int								Bureaucrat::getGrade() const {
	return (_grade);
};

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 <= 0) {
		throw GradeTooHighException();
	}
	_grade--;
};

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
	_grade++;
};

void	Bureaucrat::signForm(AForm* form) {
	form->beSigned(*this);
	std::cout << this->getName() << " signed " << form->getName() << std::endl;
};

void	Bureaucrat::executeForm(AForm const & form) const {
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "outOfRange: Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "outOfRange: Grade is too low!";
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src) {
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}
