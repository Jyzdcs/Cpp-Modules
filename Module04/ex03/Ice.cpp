#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "[Ice] constructor called\n";	
}

Ice::Ice(const Ice& src) : AMateria(src) {
	std::cout << "[Ice] copy constructor called\n";
};

Ice& Ice::operator=(const Ice& src) {
	if (this == &src) return *this;

	this->type = src.type;
	return *this;
};

Ice::~Ice() {
	std::cout << "[Ice] destructor called\n";
};

AMateria*	Ice::clone() const {
	return new Ice();
};

void			Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
};
