#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {
	std::cout << "[Cure] constructor called\n";	
}

Cure::Cure(const Cure& src) : AMateria(src) {
	std::cout << "[Cure] copy constructor called\n";
};

Cure& Cure::operator=(const Cure& src) {
	if (this == &src) return *this;

	this->type = src.type;
	return *this;
};

Cure::~Cure() {
	std::cout << "[Cure] destructor called\n";
};

AMateria*	Cure::clone() const {
	return new Cure();
};

void			Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
};
