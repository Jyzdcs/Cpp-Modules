#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie stackZombie = Zombie(name);
	stackZombie.announce();
}