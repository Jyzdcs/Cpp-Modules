#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "[WrongCat] constructor called\n";
};

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src.type) {
	std::cout << "[WrongCat] copy constructor called\n";
};

WrongCat& WrongCat::operator=(const WrongCat &src) {
	if (&src != this) {
		this->type = src.type;
	};
	return *this;
};

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] destructor called\n";
}

void	WrongCat::makeSound() {
	std::cout << "Meow meow !\n";
}