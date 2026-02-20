#ifndef SHRUBERRY_CREATION_FORM_HPP
#define SHRUBERRY_CREATION_FORM_HPP
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:

	public:
		ShrubberyCreationForm(const std::string name, const int gradeToSign, const int gradeToExec);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		virtual ~ShrubberyCreationForm() = 0;
};


#endif