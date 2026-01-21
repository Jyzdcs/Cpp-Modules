#include "ScavTrap.hpp"

int main(void) {
	ScavTrap scav2("scav2");

	ClapTrap trap1 = scav2;
	ClapTrap trap2("trap2");

	trap1.attack("test1");
	trap2.attack("test2");
	// scav2 = new ScavTrap("scavtrap1");
	// scav2->attack("yo");
	// delete scav2;
	// ScavTrap* trap1 = new ScavTrap("trap1");
	// trap1->attack("test");
	// std::cout << "ScavTrap1 energy: " << trap1.getEnergy() << std::endl;
	// std::cout << "ScavTrap1 Health: " << trap1.getHealth() << std::endl;
	// std::cout << "ScavTrap1 Damage: " << trap1.getAttackDamage() << std::endl;
	// trap1.guardGate();
	// delete trap1;
}