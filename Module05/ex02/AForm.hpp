#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string		_name;
		bool								_isSigned;
		const int						_gradeToSign;
		const	int						_gradeToExec;

	public:
		AForm(const std::string name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm() = 0;
		
		const std::string		getName() const;
		bool								getIsSigned() const;
		int						getGradeToSign() const;
		int						getGradeToExec() const;

		void								beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception  {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception  {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm const& src);

#endif