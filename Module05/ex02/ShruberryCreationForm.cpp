#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const int gradeToSign, const int gradeToExec) : AForm(name, gradeToSign, gradeToExec) {
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src){

};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {

};

ShrubberyCreationForm::~ShrubberyCreationForm() {

};
