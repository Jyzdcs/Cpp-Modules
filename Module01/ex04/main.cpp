#include "FileHandler.hpp"

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Error: Invalid number of arguments"<< std::endl;
		return (false);
	}
	std::string outputFile = std::string(av[1]) + ".replace";
	FileHandler fileHandler = FileHandler(outputFile);
	if (!fileHandler.setFileContent(av[1])) {
		std::cerr << "Error: Failed to read file" << std::endl;
		return (false);
	}

	fileHandler.setOccurence(av[2]);
	fileHandler.setReplaceStr(av[3]);
	fileHandler.replaceOccurence();
	fileHandler.exportFileContent();

	return (0);
}