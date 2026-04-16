#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <cctype>

// class	FileHandler;

class BitcoinExchange {
	private:
		std::list<std::string>	_lines;
		std::list<std::string>	_dataCsv;
		const std::string& list_at(const std::list<std::string> &lst, std::size_t index);
		std::string& modify_list_at(std::list<std::string> &lst, std::size_t index);
		std::string	intToString(int value);
		void	splitDateIntoVector(std::string date, std::list<std::string> &v);
		bool	isValidNumber(std::string str);
		bool	isValidDateFormat(std::string date);
		bool	isOnlyDigit(std::string str);

		double	searchInDays(std::string year, std::string month);
		double	searchInMonths(std::string year);
		double	searchInYears(std::string year);


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
				
				std::list<std::string> _fileContent;

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