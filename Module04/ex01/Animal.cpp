#include "Animal.hpp"

Animal::Animal() : type("undefined") {
	std::cout << "[Animal] default constructor called\n";
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "[Animal] constructor called\n";
};

Animal::Animal(const Animal &src) : type(src.type) {
	std::cout << "[Animal] copy constructor called\n";
};

Animal& Animal::operator=(const Animal &src) {
	if (&src != this) {
		this->type = src.type;
	};
	return *this;
};

Animal::~Animal() {
	std::cout << "[Animal] destructor called\n";
}

std::string	Animal::getType() {
	return this->type;
}

void	Animal::makeSound() {
	std::cout << "Im an animal\n";
}