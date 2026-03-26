#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "[BitcoinExchange] ctor called" << std::endl;
};

BitcoinExchange::~BitcoinExchange() {
	std::cout << "[BitcoinExchange] dtor called" << std::endl;
};

bool	BitcoinExchange::isValidNumber(std::string str) {
	int	virguleCount = 0;
	for (size_t i = 0; i < str.size(); i++) {
		if (i != 0 and str[i] == '.' and virguleCount == 0)	virguleCount++;
		else if (!std::isdigit(str[i])) {
			return false;
		}
	}
	if (0 < atoi(str.c_str()) and atoi(str.c_str()) < 1000)
		return true;
	return false;
};

bool	BitcoinExchange::isOnlyDigit(std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))	return false;
	}
	return true;
};

bool	BitcoinExchange::isValidDateFormat(std::string str) {
	std::vector<std::string>	date;

	size_t	pos = str.find("-");
	while (pos != std::string::npos) {
		date.push_back(str.substr(0, pos));
		str.erase(0, pos + 1);
		pos = str.find("-");
	};
	date.push_back(str);
	if (date.size() != 3)	return false;
	for (size_t	i = 0; i < date.size(); i++) {
		if (!isOnlyDigit(date[i]))	return false;
	};
	if (atoi(date[0].c_str()) < 2009)	return false;
	if (atoi(date[1].c_str()) < 1)	return false;
	if (atoi(date[2].c_str()) < 1)	return false;
	return true;
};

bool	BitcoinExchange::isValidExtension(std::string fileName) {
	if (fileName.substr(fileName.find_last_of(".") + 1) == ".csv") {
		return true;
	}
	return false;
};

double		BitcoinExchange::getDateValue(std::string date) {
	std::vector<std::string>	dataCsv;
	std::string								value;
	dataCsv.swap(fileHandler._fileContent);

	fileHandler.extractFileContent("./data.csv");
	for (size_t i = 1; i < dataCsv.size(); i++) {
		if (dataCsv[i].find(date) != std::string::npos) {
			value.append(dataCsv[i].substr(dataCsv[i].find(",") + 1));
			std::cout << "value found: " << std::strtod(value.c_str(), NULL) << std::endl;
			return std::strtod(value.c_str(), NULL);
		};
	}
	return 0;
};

void BitcoinExchange::calculBtc() {
	double	value;
	double	result;
	
	_lines.swap(fileHandler._fileContent);
	if (_lines[0] != "date | value")	{
		std::cout << "Error: invalid first line" << std::endl;
	};
	for (size_t i = 1; i < _lines.size(); i++) {
		if (_lines[i].find(" | ") == std::string::npos)	{
			std::cout << "Error: invalid input missing | " << std::endl;
		} else {
			std::vector<std::string>	linePart;
			std::string	date;
			std::string	multiplier;
			date.append(_lines[i].substr(0, _lines[i].find(" | ")));
			_lines[i].erase(0, _lines[i].find(" | ") + 3);
			multiplier.append(_lines[i]);
			if (!isValidNumber(multiplier)) {
				std::cout << "Error: invalid number value = " << multiplier << std::endl;
			} else {
				if (!isValidDateFormat(date)) {
					std::cout << "Error: invalid date format = " << date << std::endl;
				} else {
					// std::cout << "Success: valid date format = " << date << std::endl;
					value = getDateValue(date);
					// std::cout << "value of date '" << date << "' = " << value << std::endl;
					result = value * std::strtod(multiplier.c_str(), NULL);
					std::cout << date << " => " << multiplier << " = " << result << std::endl;
				}
			}
		}
	}
};

void	BitcoinExchange::printInput() {
	for (std::vector<std::string>::iterator it = _lines.begin(); it != _lines.end(); ++it) {
		std::cout << *it << std::endl; 
	};
};

BitcoinExchange::FileHandler::FileHandler() {
	std::cout << "[FileHandler] ctor called" << std::endl;
};

BitcoinExchange::FileHandler::~FileHandler() {
	std::cout << "[FileHandler] dtor called" << std::endl;
};

void	BitcoinExchange::FileHandler::extractFileContent(std::string path) {
	std::ifstream file(path.c_str());
	if (!file.is_open()) {
		throw FileExtractFailed();
	}

	std::string line;

	while (std::getline(file, line)) {
		_fileContent.push_back(line);
	}
	
	file.close();
}

void	BitcoinExchange::FileHandler::printFileContent() {
	for (std::vector<std::string>::iterator it = _fileContent.begin(); it != _fileContent.end(); ++it) {
		std::cout << *it << std::endl; 
	};
};

const char *BitcoinExchange::FileHandler::FileExtractFailed::what() const throw() {
	return "Error: Failed to extract the file content";
};

const char *BitcoinExchange::FileHandler::InvalidFileStructure::what() const throw() {
	return "ParsingError: Invalid file structure";
};