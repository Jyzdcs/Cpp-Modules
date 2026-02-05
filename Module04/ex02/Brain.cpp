#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] default constructor called\n";
};

Brain::Brain(const Brain &src) : _ideas(src._ideas) {
	std::cout << "[Brain] copy constructor called\n";
};

Brain& Brain::operator=(const Brain &src) {
	std::cout << "Assign operator called\n";
	if (&src != this) {
		for (int i = 0; i < 99; i++) {
			this->_ideas[i] = src._ideas[i];
		};
	};
	return *this;
};

Brain::~Brain() {
	std::cout << "[Brain] destructor called\n";
};

std::string*	Brain::getIdeas() {
	return _ideas;
};

int		Brain::getIdeasNbr() const {
	int len;

	for (len = 0; _ideas[len] != ""; len++) {};

	return len;
}

void	Brain::setIdea(std::string idea) {
	int len = this->getIdeasNbr();
	
	if (len >= 99) 
	{
		std::cout << "Ideas's is full\n";
		return ;
	};

	_ideas[len] = idea;
};

void	Brain::printIdeas() const {
	for (int i = 0; _ideas[i] != ""; i++) {
		std::cout << _ideas[i] << std::endl;
	};
}
