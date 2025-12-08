#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main() {
	Zombie* horde = zombieHorde(5, "bertrand");
	delete[] horde;
}