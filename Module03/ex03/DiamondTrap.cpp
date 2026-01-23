#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	_name = "Unknown";
	_energy = 50;
	std::cout << "DiamondTrap " << _name << " default constructor called\n";
};

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	_name = name;
	_energy = 50;
	std::cout << "DiamondTrap " << _name << " parameter constructor called\n";
};

DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << "DiamondTrap " << _name << " copy constructor called\n";
};

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src) {
	std::cout << "Assignement operator used\n";
	if (&src != this) {
		this->_name = src._name;
		ClapTrap::_name = src._name + "_clap_name";
		this->_attackDamage = src._attackDamage;
		this->_energy = src._energy;
		this->_health = src._health;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called\n";
}

void	DiamondTrap::whoAmI() {
	std::cout << "Hi my realName is " << this->_name << std::endl;
	std::cout << "And my clapTrap name is " << ClapTrap::_name << std::endl;
}
