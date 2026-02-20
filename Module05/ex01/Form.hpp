#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string		_name;
		bool								_isSigned;
		const int						_gradeToSign;
		const	int						_gradeToExec;

	public:
		Form(const std::string name, const int gradeToSign, const int gradeToExec);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();
		
		const std::string		getName() const;
		bool								getIsSigned() const;
		int						getGradeToSign() const;
		int						getGradeToExec() const;

		void								beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : std::exception  {
			const char* what() const throw();
		};

		class GradeTooLowException : std::exception  {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form const& src);

#endif