#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "unkown";
	_health = 100;
	_energy = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " default constructor called\n";
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_health = 100;
	_energy = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called\n";
};

ScavTrap::ScavTrap(ScavTrap const& src) 
		:  ClapTrap(src) {
	std::cout << "ScavTrap " << _name << " copy constructor called\n";
};

ScavTrap& ScavTrap::operator=(ScavTrap const& src) {
	if (&src != this) {
		this->_name = src._name;
		this->_attackDamage = src._attackDamage;
		this->_energy = src._energy;
	}
	return *this;
};

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called\n";
};

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in gateKeeper mode!\n";
};

void  ScavTrap::attack(const std::string& target) {
	if (this->_health > 0 && this->_energy > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
		_energy -= 1;
	} else {
		std::cout << "ScavTrap " << this->_name << " can't attack cause of health or energy !\n";
	}
};
