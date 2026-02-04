#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain) {
	// _brain = new Brain();
	std::cout << "[Cat] constructor called\n";
};

Cat::Cat(const Cat &src) : Animal(src.type) {
	this->_brain = new Brain();
	std::string *ideas = src._brain->getIdeas();

	for (int i = 0; i < src._brain->getIdeasNbr(); i++) {
		this->_brain->setIdea(ideas[i]);
	};

	std::cout << "[Cat] copy constructor called\n";
};

Cat& Cat::operator=(const Cat &src) {
	if (&src != this) {
		this->type = src.type;
		this->_brain = src._brain;
	};
	return *this;
};

Cat::~Cat() {
	delete _brain;
	std::cout << "[Cat] destructor called\n";
}

void	Cat::makeSound() {
	std::cout << "Meow meow !\n";
}

void	Cat::setIdea(std::string idea) {
	_brain->setIdea(idea);
}

Brain* Cat::getBrain() {
	return _brain;
};