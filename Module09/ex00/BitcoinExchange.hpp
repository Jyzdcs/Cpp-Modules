#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

// class	FileHandler;

class BitcoinExchange {
	private:
		std::vector<std::string>	_lines;
		std::vector<std::string>	_dataCsv;
		void	splitDateIntoVector(std::string date, std::vector<std::string> &v);
		bool	isValidNumber(std::string str);
		bool	isValidDateFormat(std::string date);
		bool	isOnlyDigit(std::string str);

	public:
		BitcoinExchange();
		~BitcoinExchange();

		bool	isValidExtension(std::string fileName);

		double		closestDateValue(std::string date);
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
				
				std::vector<std::string> _fileContent;

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