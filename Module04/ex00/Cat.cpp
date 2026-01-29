#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] constructor called\n";
};

Cat::Cat(const Cat &src) : Animal(src.type) {
	std::cout << "[Cat] copy constructor called\n";
};

Cat& Cat::operator=(const Cat &src) {
	if (&src != this) {
		this->type = src.type;
	};
	return *this;
};

Cat::~Cat() {
	std::cout << "[Cat] destructor called\n";
}

void	Cat::makeSound() {
	std::cout << "Meow meow !\n";
}