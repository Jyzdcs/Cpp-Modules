#include "BitcoinExchange.hpp"
#include "stdlib.h"
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange() {
	fileHandler.extractFileContent("./data.csv");
	_dataCsv.swap(fileHandler._fileContent);
	fileHandler._fileContent.clear();
	std::cout << "[BitcoinExchange] ctor called" << std::endl;
};

BitcoinExchange::~BitcoinExchange() {
	std::cout << "[BitcoinExchange] dtor called" << std::endl;
};

const std::string& BitcoinExchange::list_at(const std::list<std::string> &lst, std::size_t index) {
	if (index >= lst.size())
			throw std::out_of_range("list_at: index out of range");

	std::list<std::string>::const_iterator it = lst.begin();
	for (std::size_t i = 0; i < index; ++i)
			++it;
	return *it;
}

std::string& BitcoinExchange::modify_list_at(std::list<std::string> &lst, std::size_t index) {
	if (index >= lst.size())
			throw std::out_of_range("list_at: index out of range");

	std::list<std::string>::iterator it = lst.begin();
	for (std::size_t i = 0; i < index; ++i)
			++it;
	return *it;
}	

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

bool	BitcoinExchange::isOnlyDigit(std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))	return false;
	}
	return true;
};

bool	BitcoinExchange::isValidDateFormat(std::string str) {
	std::list<std::string>	date;

	size_t	pos = str.find("-");
	while (pos != std::string::npos) {
		date.push_back(str.substr(0, pos));
		str.erase(0, pos + 1);
		pos = str.find("-");
	};
	date.push_back(str);
	if (date.size() != 3)	return false;
	for (size_t	i = 0; i < date.size(); i++) {
		if (!isOnlyDigit(list_at(date, i)))	return false;
	};
	if (atoi(list_at(date, 0).c_str()) < 2009)	return false;
	if (atoi(list_at(date, 1).c_str()) < 1 || list_at(date, 1).length() != 2)	return false;
	if (atoi(list_at(date, 2).c_str()) < 1 || list_at(date, 2).length() != 2)	return false;
	return true;
};

bool	BitcoinExchange::isValidExtension(std::string fileName) {
	if (fileName.substr(fileName.find_last_of(".") + 1) == ".csv") {
		return true;
	}
	return false;
};


double	BitcoinExchange::searchInDays(std::string year, std::string month) {
	std::string	value;

	for (int dayNum = 31; dayNum > 0; dayNum--) {
		std::string tmpDate = year + "-" + month;
		tmpDate += dayNum < 10 ? "-0" + intToString(dayNum) : "-" + intToString(dayNum);
		for (size_t	i = 0; i < _dataCsv.size(); i++) {
			if (list_at(_dataCsv, i).find(tmpDate) != std::string::npos) {
				size_t	valueIdx = list_at(_dataCsv, i).find(",") + 1;
				value = list_at(_dataCsv, i).substr(valueIdx);
				// std::cout << "date found: " << year << "-" << month << "-" << intToString(dayNum) << std::endl;
				return std::strtod(value.c_str(), NULL);
			}
		}
	}
	return -1;
};

double	BitcoinExchange::searchInMonths(std::string year) {
	double value;

	for (int monthNum = 12; monthNum > 0; monthNum--) {
		value = searchInDays(year, intToString(monthNum));
		if (value != -1)	return value;
	}
	return -1;
};

double	BitcoinExchange::searchInYears(std::string year) {
	double value;

	for (int yearNum = atoi(year.c_str()); yearNum > 2008; yearNum--) {
		value = searchInMonths(intToString(yearNum));
		if (value != -1)	return value;
	}
	return -1;
};

double		BitcoinExchange::closestDateValue(std::string date) {
	std::string								year;
	std::string								month;
	std::string								value;
	std::list<std::string>	splittedDate;

	splitDateIntoVector(date, splittedDate);
	year = list_at(splittedDate, 0);
	month = list_at(splittedDate, 1);
	for (int day = atoi(list_at(splittedDate, 2).c_str()); day > 0; day--) {
		std::string tmpDate = year;
		tmpDate += "-" + month;
		tmpDate += day < 10 ? "-0" + intToString(day) : "-" + intToString(day);
		for (size_t i = 1; i < _dataCsv.size(); i++) {
			if (list_at(_dataCsv, i).find(tmpDate) != std::string::npos) {
				// std::cout << "date found: " << year << "-" << month << "-" << intToString(day) << std::endl;
				value.append(list_at(_dataCsv, i).substr(list_at(_dataCsv, i).find(",") + 1));
				return std::strtod(value.c_str(), NULL);
			}
		}
	}
	return searchInYears(list_at(splittedDate, 0));
};

double		BitcoinExchange::getDateValue(std::string date) {
	std::string								value;

	if (atoi(date.substr(0, date.find("-")).c_str()) > 2022) {
		return std::strtod(list_at(_dataCsv, _dataCsv.size() - 1).substr(list_at(_dataCsv, _dataCsv.size() - 1).find(",") + 1).c_str(), NULL);
	}
	return closestDateValue(date);
};

void BitcoinExchange::calculBtc() {
	double	value;
	double	result;
	
	_lines.swap(fileHandler._fileContent);
	if (list_at(_lines, 0) != "date | value")	{
		std::cout << "Error: invalid first line" << std::endl;
	};
	for (size_t i = 1; i < _lines.size(); i++) {
		if (list_at(_lines, i).find(" | ") == std::string::npos)	{
			std::cout << "Error: invalid input missing | " << std::endl;
		} else {
			std::list<std::string>	linePart;
			std::string	date;
			std::string	multiplier;
			date.append(list_at(_lines, i).substr(0, list_at(_lines, i).find(" | ")));
			modify_list_at(_lines, i).erase(0, list_at(_lines, i).find(" | ") + 3);
			multiplier.append(list_at(_lines, i));
			if (!isValidNumber(multiplier)) {
				std::cout << "Error: invalid number value = " << multiplier << std::endl;
			} else {
				if (!isValidDateFormat(date)) {
					std::cout << "Error: invalid date format = " << date << std::endl;
				} else {
					value = getDateValue(date);
					result = value * std::strtod(multiplier.c_str(), NULL);
					std::cout << date << " => " << multiplier << " = " << result << std::endl;
				}
			}
		}
	}
};

void	BitcoinExchange::printInput() {
	for (std::list<std::string>::iterator it = _lines.begin(); it != _lines.end(); ++it) {
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
	for (std::list<std::string>::iterator it = _fileContent.begin(); it != _fileContent.end(); ++it) {
		std::cout << *it << std::endl; 
	};
};

const char *BitcoinExchange::FileHandler::FileExtractFailed::what() const throw() {
	return "Error: Failed to extract the file content";
};

const char *BitcoinExchange::FileHandler::InvalidFileStructure::what() const throw() {
	return "ParsingError: Invalid file structure";
};