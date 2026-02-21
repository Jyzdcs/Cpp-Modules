#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

class Bureaucrat {
	private:
		const std::string 	_name;
		int									_grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		const std::string	getName() const;
		int								getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm* form);
		void	executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src);

#endif