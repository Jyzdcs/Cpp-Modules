#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
	Character jyzdcs("Jyzdcs");
	Ice				*ice = new Ice();
	Cure				*cure = new Cure();
	// Ice				*ice = new Ice();
	// Ice				*ice = new Ice();

	jyzdcs.equip(ice);
	jyzdcs.equip(cure);
	delete ice;
	jyzdcs.unequip(0);
	jyzdcs.use(1, jyzdcs);
	delete cure;
}