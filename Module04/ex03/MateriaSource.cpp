#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0) {
	for (int i = 0; i < 4; i++) {
		_learned[i] = NULL;
	}

	std::cout << "[MateriaSource] constructor called\n";
};

MateriaSource::MateriaSource(const MateriaSource& src) : _idx(0) {
	for (int i = 0; i < 4; i++) {
		_learned[i] = NULL;
	}
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
		if (_learned[i] != NULL) {
			delete _learned[i];
			_learned[i] = NULL;
		}
	}
	std::cout << "[MateriaSource] destructor called\n";
};

int				MateriaSource::getLearnedNbr() {
	int i = 0;

	while (_learned[i]) i++;
	return i;
};

bool				MateriaSource::isUniqueMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (_learned[i] != NULL and _learned[i] == materia) return false;
	}
	return true;
};

void				MateriaSource::learnMateria(AMateria* materia) {
	if (!materia) {
		std::cout << "NULL param\n";
		return ;
	}
	if (_idx < 4 and _learned[_idx] == NULL)
	{
		std::cout << "AMateria " << materia->getType() << " has been learned\n";
		std::cout << 4 - _idx - 1 << " slots remaining\n";
		if (isUniqueMateria(materia))
		{
			std::cout << "Is unique materia\n";
			_learned[_idx] = materia;
		}
		_idx++;
		return ;
	}
	std::cout << "AMateria " << materia->getType() << " wasnt learned due to lack of slots\n";
};

AMateria*		MateriaSource::createMateria(std::string const& type) {
	int i = 0;

	std::cout << type << std::endl;
	while (_learned[i] != NULL and _learned[i]->getType() != type and i < 4) {
		i++;
	};
	std::cout << _learned[i] << std::endl;
	if (i == getLearnedNbr())
	{
		std::cout << "Unknown materia given\n";
		return NULL;
	}
	std::cout << _learned[i]->getType() << " materia type created\n";
	return _learned[i]->clone();
};