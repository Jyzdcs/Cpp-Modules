#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {
	std::cout << "[AMateria] constructor called\n";
};

AMateria::AMateria(const AMateria& src) : type(src.type) {
	std::cout << "[AMateria] copy constructor called\n";
};

AMateria& AMateria::operator=(const AMateria& src) {
	if (this == &src) return *this;

	this->type = src.type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "[AMateria] destructor called\n";
}

std::string const&	AMateria::getType() {
	return type;
};

void			AMateria::use(ICharacter& target) {
	std::cout << "Actual AMateria has a undefined type nothing happend to " << target.getName() << "\n";
};
