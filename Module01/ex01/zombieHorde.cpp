#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];

	for (int j = 0; j < N; j++) {
		horde[j].setName(name);
	}

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	
	return horde;
}