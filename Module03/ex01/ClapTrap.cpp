#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknow") {
	std::cout << "ClapTrap " << _name << " default constructor called\n";
};

ClapTrap::ClapTrap(std::string name) {
	_name = name;
	_health = 10;
	_energy = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap " << _name << " constructor called\n";
};

ClapTrap::ClapTrap(ClapTrap const& src) 
		: _name(src._name), _health(src._health), _energy(src._energy), _attackDamage(src._attackDamage) {
	std::cout << "ClapTrap " << _name << " copy constructor called\n";
};

ClapTrap& ClapTrap::operator=(ClapTrap const& src) {
	if (&src != this) {
		this->_name = src._name;
		this->_attackDamage = src._attackDamage;
		this->_energy = src._energy;
		this->_health = src._health;
	}
	return *this;
};

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called\n";
};

std::string	ClapTrap::getName() const {
	return _name;
};

int					ClapTrap::getHealth() const {
	return _health;
};

int					ClapTrap::getEnergy() const {
	return _energy;
};

int					ClapTrap::getAttackDamage() const {
	return _attackDamage;
};


void  ClapTrap::attack(const std::string& target) {
	if (this->_health > 0 && this->_energy > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
		_energy -= 1;
	} else {
		std::cout << "ClapTrap " << this->_name << " can't attack cause of health or energy !\n";
	}
};

void  ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _health) {
		_health = 0;
		std::cout << "ClapTrap " << this->_name << " has lost all his hp." << " he has " << this->_health << "hp now\n";
	} else if (_health > 0) {
		_health -= amount;
		std::cout << "ClapTrap " << this->_name << " has lost " << amount << " hp" << " he has " << this->_health << "hp now\n";
	} else {
		std::cout << "ClapTrap " << this->_name << " hasnt lost his hp !\n";
	}
};

void  ClapTrap::beReparaied(unsigned int amount) {
	if (amount <= _energy) {
		_health += amount;
		_energy -= amount;
		std::cout << "ClapTrap " << _name << " used " << amount << " energy to repair. Now it has " << _energy << " energy" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " try to repair " << amount << " energy but it has only " << _energy << " energy" << std::endl;
	}
};