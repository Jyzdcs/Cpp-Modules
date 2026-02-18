#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	std::cout << "[Character] constructor called\n";
};

Character::Character(const Character& src) : _name(src.getName()) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
	};
	std::cout << "[Character] copy constructor called\n";
};

Character& Character::operator=(const Character& src) {
	if (this == &src)	return *this;

	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
	this->_name = src.getName();
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
	};
	return *this;
};

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	};
	std::cout << "[Character] destructor called\n";
};
			
std::string const&	Character::getName() const {
	return _name;
};

void								Character::equip(AMateria* m) {
	int	i = 0;

	if (!m) {
		std::cout << "Material that you gave is NULL\n";
		return ;
	}
	while (_inventory[i] != NULL && i < 4)
		i++;
	if (i == 4) {
		std::cout << _name << " Inventory is full\n";
	} else {
		_inventory[i] = m;
		std::cout << _name << " Added " << m->getType() << " to inventory\n";
	}
};

void								Character::unequip(int idx) {
	if (0 <= idx && idx <= 3) {
		_inventory[idx] = NULL;
	}
};

void								Character::use(int idx, ICharacter& target) {
	if (_inventory[idx] == NULL) {
		std::cout << _name << " Material selectionned is unavaible !\n";
		return ;
	}
	if (0 <= idx && idx <= 3) {
		_inventory[idx]->use(target);
	};
};
