#include "FragTrap.hpp"

int main(void) {
	FragTrap frag1("frag1");
	FragTrap frag2("frag2");
	FragTrap frag3;

	std::cout << frag1.getEnergy() << std::endl;
	frag1.attack("test");
	std::cout << frag1.getEnergy() << std::endl;

	// frag3 = frag2;
	std::cout << frag3.getEnergy() << std::endl;
	frag3 = frag1;
	std::cout << frag3.getEnergy() << std::endl;

	// trap1.attack("test1");
	// trap2.attack("test2");
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