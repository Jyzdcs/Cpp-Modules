#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main() {
	Zombie* heapZombie = newZombie("Heap");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stack");
}