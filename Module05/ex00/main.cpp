#include "Bureaucrat.hpp"

int main() {

	// Error tooLow
	try {
		Bureaucrat test0("kyksss", 151);
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
// ----------------------------------------------------------------------------------------------------------------
	// print test0 and test1 without error
	try {
		Bureaucrat test0("kyksss", 150);
		Bureaucrat test1("jerem", 150);

		std::cout << test0 << std::endl;
		std::cout << test1 << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
// ----------------------------------------------------------------------------------------------------------------
	// assignement operator
	try {
		Bureaucrat test0("kyksss", 150);
		Bureaucrat test1("jerem", 5);

		std::cout << test0 << std::endl;
		std::cout << test1 << std::endl;

		test1 = test0;
		std::cout << test0 << std::endl;
		std::cout << test1 << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
// ----------------------------------------------------------------------------------------------------------------
	// decrement grade make an error cause 151 > LOWEST_GRADE
	try {
		Bureaucrat test0("kyksss", 150);

		test0.decrementGrade();
		std::cout << test0 << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
// ----------------------------------------------------------------------------------------------------------------
	// increment grade make an error cause 1 < HIGHEST_GRADE
	try {
		Bureaucrat test0("kyksss", 1);

		std::cout << test0 << std::endl;
		test0.incrementGrade();
		std::cout << test0 << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
// ----------------------------------------------------------------------------------------------------------------
	// Print 2
	try {
		Bureaucrat test0("kyksss", 1);

		test0.decrementGrade();
		std::cout << test0 << std::endl;
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
}