#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
	: AForm(name, 145, 137) {
	std::cout << "[ShrubberyCreationForm] ctor called\n";
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
	std::cout << "[ShrubberyCreationForm] cpy ctor called\n";
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	if (this == &src) return *this;

	this->setIsSigned(src.getIsSigned());
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[ShrubberyCreationForm] dtor called\n";
};

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned()) {
		throw NotSigned();
	} else if (executor.getGrade() > this->getGradeToExec()) {
		throw GradeTooLowException();
	}
	executor.getName();
	std::ofstream outfile ((executor.getName() + "_shrubbery").c_str());
	outfile << "                                              ." << std::endl;
	outfile << "                                   .         ;  " << std::endl;
	outfile << "      .              .              ;%     ;;   " << std::endl;
	outfile << "        ,           ,                :;%  %;   " << std::endl;
	outfile << "         :         ;                   :;%;'     .,   " << std::endl;
	outfile << ",.        %;     %;            ;        %;'    ,;" << std::endl;
	outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	outfile << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	outfile << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
	outfile << "           `@%:.  :;%.         ;@@%;'   " << std::endl;
	outfile << "             `@%.  `;@%.      ;@@%;         " << std::endl;
	outfile << "               `@%%. `@%%    ;@@%;        " << std::endl;
	outfile << "                 ;@%. :@%%  %@@%;       " << std::endl;
	outfile << "                   %@bd%%%bd%%:;     " << std::endl;
	outfile << "                     #@%%%%%:;;" << std::endl;
	outfile << "                     %@@%%%::;" << std::endl;
	outfile << "                     %@@@%(o);  . '         " << std::endl;
	outfile << "                     %@@@o%;:(.,'         " << std::endl;
	outfile << "                 `.. %@@@o%::;         " << std::endl;
	outfile << "                    `)@@@o%::;         " << std::endl;
	outfile << "                     %@@(o)::;        " << std::endl;
	outfile << "                    .%@@@@%::;         " << std::endl;
	outfile << "                    ;%@@@@%::;.          " << std::endl;
	outfile << "                   ;%@@@@%%:;;;. " << std::endl;
	outfile << "               ...;%@@@@@%%:;;;;,.." << std::endl;
	outfile.close();
};