#include "Harl.hpp"

std::string toUpper(std::string str) {
	int i = 0;
	std::string upperStr = "";

	while (str[i])
		upperStr += static_cast<char>(std::toupper(static_cast<unsigned char>(str[i++])));
	return (upperStr);
}

int main(int ac, char **av) {
	if (ac != 2) {
		return (1);
	}
	Harl harl = Harl();
	std::cout << toUpper(av[1]) + "\n";
	harl.complain(toUpper(av[1]));
}