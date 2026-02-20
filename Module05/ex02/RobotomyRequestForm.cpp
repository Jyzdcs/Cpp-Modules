#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const int gradeToSign, const int gradeToExec) : AForm(name, gradeToSign, gradeToExec) {
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src){

};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {

};

RobotomyRequestForm::~RobotomyRequestForm() {

};
