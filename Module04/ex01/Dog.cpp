#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain) {
	std::cout << "[Dog] constructor called\n";
};

Dog::Dog(const Dog &src) : Animal(src.type) {
	this->_brain = new Brain();
	std::string *ideas = src._brain->getIdeas();

	for (int i = 0; i < src._brain->getIdeasNbr(); i++) {
		this->_brain->setIdea(ideas[i]);
	};

	std::cout << "[Dog] copy constructor called\n";
};

Dog& Dog::operator=(const Dog &src) {
	if (&src != this) {
		this->type = src.type;
		this->_brain = src._brain;
	};
	return *this;
};

Dog::~Dog() {
	delete _brain;
	std::cout << "[Dog] destructor called\n";
}

void Dog::makeSound() {
	std::cout << "Waouf waouf !\n";
};

void	Dog::setIdea(std::string idea) {
	_brain->setIdea(idea);
}

Brain* Dog::getBrain() {
	return _brain;
}