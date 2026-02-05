#include "AAnimal.hpp"

AAnimal::AAnimal() : type("undefined") {
	std::cout << "[AAnimal] default constructor called\n";
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "[AAnimal] constructor called\n";
};

AAnimal::AAnimal(const AAnimal &src) : type(src.type) {
	std::cout << "[AAnimal] copy constructor called\n";
};

AAnimal& AAnimal::operator=(const AAnimal &src) {
	if (&src != this) {
		this->type = src.type;
	};
	return *this;
};

AAnimal::~AAnimal() {
	std::cout << "[AAnimal] destructor called\n";
}

std::string	AAnimal::getType() {
	return this->type;
}

void	AAnimal::makeSound() {
	std::cout << "Im an AAnimal\n";
}