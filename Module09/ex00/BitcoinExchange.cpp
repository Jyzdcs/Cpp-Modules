#include "BitcoinExchange.hpp"
#include "stdlib.h"
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange() {
	fileHandler.extractFileContent("./data.csv");
	for (size_t i = 1; i < fileHandler._fileContent.size(); i++) {
		_dataCsv[dateToInt(extractDateFromCsv(fileHandler._fileContent[i]))] = extractValueFromCsv(fileHandler._fileContent[i]);
	}
	// for (std::map<int, double>::iterator it = _dataCsv.begin(); it != _dataCsv.end(); ++it) {
		// std::cout << it->first << " " << it->second << std::endl; 
	// };
	fileHandler._fileContent.clear();
	// std::cout << "[BitcoinExchange] ctor called" << std::endl;
};

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "[BitcoinExchange] dtor called" << std::endl;
};

std::string	BitcoinExchange::extractDateFromCsv(std::string line) {
	// std::cout << line.substr(0, line.find_first_of(',')) << std::endl;
	return line.substr(0, line.find_first_of(','));
};

std::string	BitcoinExchange::extractDateFromTxt(std::string line) {
	// std::cout << line.substr(0, line.find_first_of(',')) << std::endl;
	return line.substr(0, line.find_first_of(' '));
};

double	BitcoinExchange::extractValueFromCsv(std::string line) {
	// std::cout << line.substr(line.find_first_of(',') + 1) << std::endl;
	return std::strtod(line.substr(line.find_first_of(',') + 1).c_str(), NULL);
};

int		BitcoinExchange::dateToInt(std::string str) {
	int year = atoi(str.substr(0, str.find_first_of("-")).c_str());
	int month = atoi(str.substr(str.find_first_of("-") + 1, 2).c_str());
	int day = atoi(str.substr(str.find_last_of("-") + 1).c_str());

	// std::cout << (year * 10000) + (month * 100) + day << std::endl;
	return (year * 10000) + (month * 100) + day;
};

std::string BitcoinExchange::intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void	BitcoinExchange::splitDateIntoVector(std::string date, std::list<std::string> &v) {
	size_t	pos = date.find("-");
	while (pos != std::string::npos) {
		v.push_back(date.substr(0, pos));
		date.erase(0, pos + 1);
		pos = date.find("-");
	};
	v.push_back(date);
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

bool	BitcoinExchange::isOnlyDigitAndHyphen(std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]) && str[i] != '-')	return false;
	}
	return true;
};

bool	BitcoinExchange::isValidDateFormat(std::string date) {
	size_t	firstHyphenIdx;
	size_t	secondHyphenIdx;
	if (date.size() != 10)	return false;
	firstHyphenIdx = date.find_first_of('-');
	secondHyphenIdx = date.find_last_of('-');
	if (firstHyphenIdx != std::string::npos and secondHyphenIdx != std::string::npos and secondHyphenIdx - firstHyphenIdx == 3) {
		if (!isOnlyDigitAndHyphen(date))	return false;
		if (atoi(date.substr(0, 4).c_str()) < 2009)	return false;
		if (atoi(date.substr(5, 2).c_str()) < 1 || atoi(date.substr(5, 2).c_str()) > 12)	return false;
		if (atoi(date.substr(8, 2).c_str()) < 1 || atoi(date.substr(8, 2).c_str()) > 31 || atoi(date.substr(8, 2).c_str()) < 1)	return false;
	} else {
		return false;
	}
	return true;
};

bool	BitcoinExchange::isValidExtension(std::string fileName) {
	if (fileName.substr(fileName.find_last_of(".") + 1) == ".csv") {
		return true;
	}
	return false;
};

double		BitcoinExchange::closestDateValue(int date) {
	int	closestDate = date - 1;
	int	closestDateValue = -1;
	while (_dataCsv.find(closestDate) == _dataCsv.end()) {
		closestDate--;
	};
	closestDateValue = _dataCsv[closestDate];
	// std::cout << "closestDate found = " << closestDate << std::endl;
	// std::cout << "closestValue found = " << closestDateValue << std::endl;
	return closestDateValue;
}

double		BitcoinExchange::getDateValue(std::string date) {
	if (dateToInt(date) > 20220329) {
		return 47115.93;
	} else if (dateToInt(date) < 20100817) {
		return 0;
	};

	std::map<int, double>::iterator	value = _dataCsv.find(dateToInt(date));
	if (value == _dataCsv.end()) {
		return closestDateValue(dateToInt(date));
	}
	return value->second;
};


void BitcoinExchange::calculBtc() {
	double	result;
	std::string	dateOfTxt;
	std::string			multiplier;
	
	std::cout << fileHandler._fileContent[0] << std::endl;
	_lines.swap(fileHandler._fileContent);
	if (_lines.find(0)->second != "date | value")	{
		std::cout << "Error: invalid first line" << std::endl;
	};
	for (size_t i = 1; i < _lines.size(); i++) {
		if (_lines[i].find(" | ") == std::string::npos)	{
			std::cout << "Error: invalid input missing | " << std::endl;
		} else {
			dateOfTxt = extractDateFromTxt(_lines[i]);
			multiplier = _lines[i].substr(_lines[i].find_first_of("|") + 2).c_str();
			if (!isValidNumber(multiplier)) {
				std::cout << "Error: invalid number value = " << multiplier << std::endl;
			} else {
				if (!isValidDateFormat(dateOfTxt)) {
					std::cout << "Error: invalid date format = " << dateOfTxt << std::endl;
				} else {
					result = getDateValue(dateOfTxt) * std::strtod(multiplier.c_str(), NULL);
					std::cout << dateOfTxt.substr(0, dateOfTxt.find_first_of(" ")) << " => " << multiplier << " = " << result << std::endl;
				}
			}
		}
	}
};

void	BitcoinExchange::printInput() {
	for (std::map<int, std::string>::iterator it = _lines.begin(); it != _lines.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl; 
	};
};

BitcoinExchange::FileHandler::FileHandler() {
	// std::cout << "[FileHandler] ctor called" << std::endl;
};

BitcoinExchange::FileHandler::~FileHandler() {
	// std::cout << "[FileHandler] dtor called" << std::endl;
};

void	BitcoinExchange::FileHandler::extractFileContent(std::string path) {
	std::ifstream file(path.c_str());
	int						key = 0;
	if (!file.is_open()) {
		throw FileExtractFailed();
	}

	std::string line;

	while (std::getline(file, line)) {
		_fileContent[key] = line;
		key++;
	}
	
	file.close();
}

void	BitcoinExchange::FileHandler::printFileContent() {
	for (std::map<int, std::string>::iterator it = _fileContent.begin(); it != _fileContent.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl; 
	};
};

const char *BitcoinExchange::FileHandler::FileExtractFailed::what() const throw() {
	return "Error: Failed to extract the file content";
};

const char *BitcoinExchange::FileHandler::InvalidFileStructure::what() const throw() {
	return "ParsingError: Invalid file structure";
};