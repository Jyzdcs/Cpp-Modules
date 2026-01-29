#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] constructor called\n";
};

Dog::Dog(const Dog &src) : Animal(src.type) {
	std::cout << "[Dog] copy constructor called\n";
};

Dog& Dog::operator=(const Dog &src) {
	if (&src != this) {
		this->type = src.type;
	};
	return *this;
};

Dog::~Dog() {
	std::cout << "[Dog] destructor called\n";
}

void Dog::makeSound() {
	std::cout << "Waouf waouf !\n";
};