#include "ClapTrap.hpp"

int main(void) {
	ClapTrap trap1("trap1");
	ClapTrap trap2("trap2");
	ClapTrap unknow;

	trap1.attack(trap2.getName());
	trap2.takeDamage(trap1.getAttackDamage());
	std::cout << "ClapTrap " << trap2.getName() << " has " << trap2.getEnergy() << " energy\n";
	std::cout << "ClapTrap " << trap2.getName() << " has " << trap2.getHealth() << " health\n";
	trap2.beReparaied(10);
	std::cout << "ClapTrap " << trap2.getName() << " has " << trap2.getEnergy() << " energy\n";
	std::cout << "ClapTrap " << trap2.getName() << " has " << trap2.getHealth() << " health\n";
}