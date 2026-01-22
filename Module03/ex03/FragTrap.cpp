#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << this->getName() << " default constructor called\n";
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << this->getName() << " default constructor called\n";
};

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {
	std::cout << "FragTrap " << this->getName() << " copy constructor called\n";
};

FragTrap& FragTrap::operator=(FragTrap const& src) {
	std::cout << "operator assignement called\n";
	if (&src != this) {
		this->setName(src.getName());
		this->_attackDamage = src._attackDamage;
		this->_energy = src._energy;
	};
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->getName() << " default constructor called\n";
};

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << this->getName() << " is sending a positive high-fives request\n";
};