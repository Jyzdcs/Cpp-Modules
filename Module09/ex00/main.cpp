#include <iostream>
// #include <string>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2)	return 1;
	BitcoinExchange bitcoin;

	bitcoin.fileHandler.extractFileContent(av[1]);
	try {
		bitcoin.calculBtc();
	} catch (std::exception& err) {
		std::cout << err.what() <<std::endl;
	}
};