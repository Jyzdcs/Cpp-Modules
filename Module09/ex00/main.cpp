#include <iostream>
// #include <string>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2)	return 1;
	// parser le fichier en input
	BitcoinExchange bitcoin;

	// std::string str = "salut, ca va tlmd ?";
	// std::string sub = str.substr(str.find(","));

	// std::cout << sub << std::endl;

	bitcoin.fileHandler.extractFileContent(av[1]);
	// bitcoin.fileHandler.printFileContent();
	try {
		bitcoin.calculBtc();
	} catch (std::exception& err) {
		std::cout << err.what() <<std::endl;
	}
		// verifier si le fichier contient bien 2 colonnes au debut data et value
		// verifier si chaques lignes n'a pas d'informations en trop
	// set toutes les variables private
	// appeler les methodes utilitaire pour creer le resultat final
	// print le resultat final
};