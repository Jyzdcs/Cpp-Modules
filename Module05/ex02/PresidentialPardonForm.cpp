#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string name, const int gradeToSign, const int gradeToExec) : AForm(name, gradeToSign, gradeToExec) {
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src){

};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {

};

PresidentialPardonForm::~PresidentialPardonForm() {

};
