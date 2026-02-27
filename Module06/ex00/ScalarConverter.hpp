#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#define DIGITS "0123456789"

typedef enum { CHAR, INT, FLOAT, DOUBLE, INFINITE } t_type;

class ScalarConverter {
	private:
		static bool	isChar(std::string input);
		static bool	isInt(std::string input);
		static bool	isFloat(std::string input);
		static bool	isDouble(std::string input);
		static bool	isInfinite(std::string input);

		static void	convertFromChar(std::string input);
		static void	convertToNumber(std::string input, long double nb);
		static void	convertFromInfinite(const std::string &representation);
		static void convertToChar(const char &c);

	protected:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

	public:
		~ScalarConverter();
		
		static void convert(const std::string &representation);
};

#endif