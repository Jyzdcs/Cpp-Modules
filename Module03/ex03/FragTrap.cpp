#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "[FragTrap] " << this->getName() << " default constructor called\n";
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "[FragTrap] " << this->getName() << " default constructor called\n";
};

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {
	std::cout << "[FragTrap] " << this->getName() << " copy constructor called\n";
};

FragTrap& FragTrap::operator=(FragTrap const& src) {
	std::cout << "operator assignement called\n";
	if (&src != this) {
		this->_name = src._name;
		this->_attackDamage = src._attackDamage;
		this->_energy = src._energy;
		this->_health = src._health;
	};
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] " << this->getName() << " default constructor called\n";
};

void FragTrap::highFiveGuys() {
	std::cout << "[FragTrap] " << this->getName() << " is sending a positive high-fives request\n";
};

void  FragTrap::attack(const std::string& target) {
	if (this->_health > 0 && this->_energy > 0) {
		std::cout << "[FragTrap] " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
		_energy -= 1;
	} else {
		std::cout << "[FragTrap] " << this->_name << " can't attack cause of health or energy !\n";
	}
};
