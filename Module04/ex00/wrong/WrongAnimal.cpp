#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("undefined") {
	std::cout << "[WrongAnimal] default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "[WrongAnimal] constructor called\n";
};

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type) {
	std::cout << "[WrongAnimal] copy constructor called\n";
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src) {
	if (&src != this) {
		this->type = src.type;
	};
	return *this;
};

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] destructor called\n";
}

std::string	WrongAnimal::getType() {
	return this->type;
}

void	WrongAnimal::makeSound() {
	std::cout << "Im an Wronganimal\n";
}