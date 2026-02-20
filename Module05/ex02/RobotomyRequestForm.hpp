#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:

	public:
		RobotomyRequestForm(const std::string name, const int gradeToSign, const int gradeToExec);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		virtual ~RobotomyRequestForm() = 0;
};


#endif