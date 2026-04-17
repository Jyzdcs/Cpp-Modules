#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <cctype>

// class	FileHandler;

class BitcoinExchange {
	private:
		std::map<int, std::string>	_lines;
		std::map<int, double>	_dataCsv;
		std::string	extractDateFromCsv(std::string line);
		std::string	extractDateFromTxt(std::string line);
		std::string	intToString(int value);
		int		dateToInt(std::string date);
		double	extractValueFromCsv(std::string line);
		
		void	splitDateIntoVector(std::string date, std::list<std::string> &v);
		bool	isValidNumber(std::string str);
		bool	isValidDateFormat(std::string date);
		bool	isOnlyDigitAndHyphen(std::string str);
	public:
		BitcoinExchange();
		~BitcoinExchange();

		bool	isValidExtension(std::string fileName);

		double		closestDateValue(int date);
		double		getDateValue(std::string date);

		void	calculBtc();
		void	printInput();

		class	FileHandler {
			private:
				std::string _outputFileName;
				std::string	_occurence;
				std::string _replaceStr;
				std::string _outputFileContent;
			
			public:
				FileHandler();
				~FileHandler();
				
				std::map<int, std::string> _fileContent;

				void	extractFileContent(std::string path);
				void	printFileContent();

				class FileExtractFailed : public std::exception {
					const char *what() const throw();
				};
				class InvalidFileStructure : public std::exception {
					const char *what() const throw();
				};
		};
		FileHandler								fileHandler;
};

#endif