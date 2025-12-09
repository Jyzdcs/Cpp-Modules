#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Adress : " << std::endl;
	std::cout << "	Adress of str: " << &str << std::endl;
	std::cout << "	Adress of strPTR: " << &stringPTR << std::endl;
	std::cout << "	Adress of strREF: " << &stringREF << std::endl;

	std::cout << "Value : " << std::endl;
	std::cout << "	Value of str: " << str << std::endl;
	std::cout << "	Value of strPTR: " << *stringPTR << std::endl;
	std::cout << "	Value of strREF: " << stringREF << std::endl;
}