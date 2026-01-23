// #include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
	std::cout << "hi\n";
	// DiamondTrap diamondDefault;
	// DiamondTrap diamondParam("Param");
	// std::cout << diamondParam.getHealth() << std::endl;
	// std::cout << diamondParam.getEnergy() << std::endl;
	// std::cout << diamondParam.getAttackDamage() << std::endl;
	// diamondParam.attack("test");
	// diamondParam.whoAmI();
	// DiamondTrap test(diamondParam);
	// diamondParam.attack("test");
	// std::cout << diamondParam.getHealth() << std::endl;
	// std::cout << diamondParam.getEnergy() << std::endl;
	// std::cout << diamondParam.getAttackDamage() << std::endl;
	// diamondParam.whoAmI();


	DiamondTrap diamondCpy("robot2.1");
	DiamondTrap diamondAssignement;
	std::cout << "\n\n";

	diamondCpy.beReparaied(10);
	diamondAssignement = diamondCpy;
	// diamondAssignement.beReparaied(10);

	std::cout << "\n\n";
	diamondCpy.whoAmI();
	std::cout << "My stats are :\n";
	std::cout << "- health : " << diamondCpy.getHealth() << std::endl;
	std::cout << "- energy : " << diamondCpy.getEnergy() << std::endl;
	std::cout << "- attackDamage : " << diamondCpy.getAttackDamage() << std::endl;
	std::cout << "- attack() : ";
	diamondCpy.attack("test");
	std::cout << "\n";
	diamondAssignement.whoAmI();
	std::cout << "My stats are :\n";
	std::cout << "- health : " << diamondAssignement.getHealth() << std::endl;
	std::cout << "- energy : " << diamondAssignement.getEnergy() << std::endl;
	std::cout << "- attackDamage : " << diamondAssignement.getAttackDamage() << std::endl;
	std::cout << "- attack() : ";
	diamondAssignement.attack("test");

	std::cout << "\n\n";
}