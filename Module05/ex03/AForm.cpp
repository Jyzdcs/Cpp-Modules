#include "AForm.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) :  _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "[AForm] ctor called\n";
};

AForm::AForm(const AForm& src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	std::cout << "[AForm] copy ctor called\n";
};

AForm& AForm::operator=(const AForm& src) {
	if (this == &src) return *this;

	this->_isSigned = src._isSigned;
	return *this;
};

AForm::~AForm() {
	std::cout << "[AForm] dtor called\n";
};

const std::string		AForm::getName() const {
	return _name;
};

bool								AForm::getIsSigned() const {
	return _isSigned;
};

int						AForm::getGradeToSign() const {
	return _gradeToSign;
};

int						AForm::getGradeToExec() const {
	return _gradeToExec;
};

void								AForm::setIsSigned(bool isSigned) {
	_isSigned = isSigned;
};

void								AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign()) {
		this->_isSigned = true;
	} else {
		throw GradeTooLowException();
	};
};

const char* AForm::GradeTooHighException::what() const throw() {
	return "outOfRange: Grade is too high!";
};

const char* AForm::GradeTooLowException::what() const throw() {
	return "outOfRange: Grade is too low!";
};

const char* AForm::NotSigned::what() const throw() {
	return "contextError: grade is not signed!";
};

std::ostream& operator<<(std::ostream& os, AForm const& src) {
	if (src.getIsSigned()) {
		os << src.getName() << " Aform is signed ! The grad to sign it was " << src.getGradeToSign() << " and to exec was " << src.getGradeToExec();
	} else {
		os << src.getName() << " Aform is not signed! To sign it you must to be at least " << src.getGradeToSign() << " and to exec it " << src.getGradeToExec();
	}
	return os;
};