#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:

	public:
		PresidentialPardonForm(const std::string name, const int gradeToSign, const int gradeToExec);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		virtual ~PresidentialPardonForm() = 0;
};


#endif