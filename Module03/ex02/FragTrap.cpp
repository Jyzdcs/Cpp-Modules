#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " default constructor called\n";
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " default constructor called\n";
};

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {
	std::cout << "FragTrap " << _name << " copy constructor called\n";
};

FragTrap& FragTrap::operator=(FragTrap const& src) {
	if (&src != this) {
		this->_name = src._name;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " default constructor called\n";
};

void FragTrap::highFiveGuys() {};