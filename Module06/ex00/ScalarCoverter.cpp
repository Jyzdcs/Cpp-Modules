#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
  if (this == &src)
    return (*this);
  return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
  *this = src;
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isChar(std::string input) {
	// std::cout << "isChar ?" << std::endl;
	if (input.size() == 1 and std::isprint(input[0]) and !std::isdigit(input[0])) {
		std::cout << "true\n";
		return true;
	}
	return false;
};

bool	ScalarConverter::isInt(std::string input) {
	// std::cout << "isInt ?" << std::endl;
	const size_t	sign = input.find("-");

	if (sign != 0 and sign != std::string::npos)
		return false;
	if (input.find_first_not_of(DIGITS, sign == std::string::npos ? 0 : 1) != std::string::npos)
		return false;
	return true;
};

bool	ScalarConverter::isFloat(std::string input) {
	// std::cout << "isFloat ?" << std::endl;
	const size_t	sign = input.find("-");

	if (sign != 0 and sign != std::string::npos)
		return false;
	const size_t dot = input.find('.');
  if (dot == std::string::npos)
    return (false);
  if (input[input.size() - 1] != 'f')
    return (false);
  const size_t index = sign == 0 ? 1 : 0;
  const std::string decimalPart = input.substr(index, dot - index);
  const std::string fractionalPart = input.substr(dot + 1, input.size() - (dot + 2));
  if (decimalPart.find_first_not_of(DIGITS) != std::string::npos or
      fractionalPart.find_first_not_of(DIGITS) != std::string::npos)
    return (false);
  return (!decimalPart.empty() and !fractionalPart.empty());
};

bool	ScalarConverter::isDouble(std::string input) {
	// std::cout << "isDouble ?" << std::endl;
	const size_t	sign = input.find("-");

	if (sign != 0 and sign != std::string::npos)
		return false;
	const size_t dot = input.find('.');
  if (dot == std::string::npos)
    return (false);
  const size_t index = sign == 0 ? 1 : 0;
  const std::string decimalPart = input.substr(index, dot - index);
  const std::string fractionalPart = input.substr(dot + 1, input.size() - (dot + 1));
  if (decimalPart.find_first_not_of(DIGITS) != std::string::npos or
      fractionalPart.find_first_not_of(DIGITS) != std::string::npos)
    return (false);
  return (!decimalPart.empty() and !fractionalPart.empty());
};

bool	ScalarConverter::isInfinite(std::string input) {
  if (input == "-inff" or input == "+inff" or
      input == "nanf" or input == "-inf" or
      input == "+inf" or input == "nan")
    return true;
  return false;
};

void	ScalarConverter::convertToChar(const char &c) {
	if (std::isprint(c)) {
		std::cout << "char: " << "'" << c << "'" << std::endl;
	} else {
		std::cout << "char: " << "No displayable" << std::endl;
	}
};

// char = ascii number, sinn message perso
// int = parsing puis nbr
void	ScalarConverter::convertFromChar(std::string input) {
	std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
};

void	ScalarConverter::convertToNumber(std::string input, long double nb) {
  if (nb < std::numeric_limits<char>::min() or nb > std::numeric_limits<char>::max())
    std::cout << "char: overflows" << std::endl;
  else
    convertToChar(static_cast<char>(nb));
	// Si est hors limite, print overflows
  if (nb < std::numeric_limits<int>::min() or nb > std::numeric_limits<int>::max())
    std::cout << "int: overflows" << std::endl;
	// sinn atoi et print le bon nbr
  else
    std::cout << "int: " << std::atoi(input.c_str()) << std::endl;
  if (nb < -std::numeric_limits<float>::max() or nb > std::numeric_limits<float>::max())
    std::cout << "float: overflows" << std::endl;
  else
    std::cout << "float: " << std::strtof(input.c_str(), NULL) << "f" << std::endl;
  if (nb < -std::numeric_limits<double>::max() or nb > std::numeric_limits<double>::max())
    std::cout << "double: overflows" << std::endl;
  else
    std::cout << "double: " << std::strtod(input.c_str(), NULL) << std::endl;
};

void ScalarConverter::convertFromInfinite(const std::string &representation) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (representation.find("nan") != std::string::npos) {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else {
    std::cout << "float: " << representation[0] << "inff" << std::endl;
    std::cout << "double: " << representation[0] << "inf" << std::endl;
  }
}


void ScalarConverter::convert(const std::string &input) {
  if (isChar(input)) {
    convertFromChar(input);
  } else if (isInt(input)) {
    convertToNumber(input, std::strtold(input.c_str(), NULL));
  } else if (isFloat(input)) {
    convertToNumber(input, std::strtold(input.c_str(), NULL));
  } else if (isDouble(input)) {
    convertToNumber(input, std::strtold(input.c_str(), NULL));
  } else if (isInfinite(input)) {
    convertFromInfinite(input);
  } else
    std::cout << "Unknown type" << std::endl;
}