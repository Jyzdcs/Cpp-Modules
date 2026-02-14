#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_learned[i] = NULL;
	}

	std::cout << "[MateriaSource] constructor called\n";
};

MateriaSource::MateriaSource(const MateriaSource& src) {
	for (int i = 0; i < 4; i++) {
		_learned[i] = src._learned[i]->clone();
	}

	std::cout << "[MateriaSource] copy constructor called\n";
};

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	if (this == &src) return *this;

	for (int i = 0; i < 4; i++) {
		delete _learned[i];
	}
	for (int i = 0; i < 4; i++) {
		_learned[i] = src._learned[i]->clone();
	}
	return *this;
};

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_learned[i] != NULL)
			delete _learned[i];
	}
	std::cout << "[MateriaSource] destructor called\n";
};

void				MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (_learned[i] != NULL)
			_learned[i] = materia;
	}
};

AMateria*		MateriaSource::createMateria(std::string const& type) {
	int i = 0;

	while (_learned[i]->getType() != type and i < 4) {
		i++;
	};

	if (i == 4)
	{
		std::cout << "Unknown materia given\n";
		return NULL;
	}
	return _learned[i];
};