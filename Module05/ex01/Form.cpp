#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) :  _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "[Form] ctor called\n";
};

Form::Form(const Form& src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	std::cout << "[Form] copy ctor called\n";
};

Form& Form::operator=(const Form& src) {
	if (this == &src) return *this;

	this->_isSigned = src._isSigned;
	return *this;
};

Form::~Form() {
	std::cout << "[Form] dtor called\n";
};

const std::string		Form::getName() const {
	return _name;
};

bool								Form::getIsSigned() const {
	return _isSigned;
};

int						Form::getGradeToSign() const {
	return _gradeToSign;
};

int						Form::getGradeToExec() const {
	return _gradeToExec;
};

void								Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign()) {
		this->_isSigned = true;
	} else {
		throw GradeTooLowException();
	};
};

const char* Form::GradeTooHighException::what() const throw() {
	return "outOfRange: Grade is too high!";
};

const char* Form::GradeTooLowException::what() const throw() {
	return "outOfRange: Grade is too low!";
};

std::ostream& operator<<(std::ostream& os, Form const& src) {
	if (src.getIsSigned()) {
		os << src.getName() << " form is signed ! The grad to sign it was " << src.getGradeToSign() << " and to exec was " << src.getGradeToExec();
	} else {
		os << src.getName() << " form is not signed! To sign it you must to be at least " << src.getGradeToSign() << " and to exec it " << src.getGradeToExec();
	}
	return os;
};