#include "Bureaucrat.hpp"

int main() {

	// ----------- Normal case -----------
	try {
		Bureaucrat	kyks("kyks", 42);
		Form				form01("impots", 50, 45);

		kyks.signedForm(form01);
	} catch (std::exception err) {
		std::cout << err.what() << std::endl;
	};
}