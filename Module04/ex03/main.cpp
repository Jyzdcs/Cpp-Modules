#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
	// -------------- DESTRUCTOR MATERIASOURCE --------------

	// -------------- DESTRUCTOR MATERIASOURCE --------------
	// MateriaSource source;
	// Cure*					cure = new Cure();
	// Cure*					cure1 = new Cure();

	// source.learnMateria(cure);
	// source.learnMateria(cure);
	// source.learnMateria(cure);
	// source.learnMateria(cure1);

	// -------------- DEEP COPY --------------
	// Character jyzdcs("Jyzdcs");
	// Ice				*ice01 = new Ice();
	// Cure				*cure01 = new Cure();
	// Ice				*ice02 = new Ice();
	// Ice				*ice03 = new Ice();
	// std::cout << std::endl;

	// jyzdcs.equip(ice01);
	// jyzdcs.equip(ice02);
	// jyzdcs.equip(ice03);
	// jyzdcs.equip(cure01);

	// std::cout << std::endl;
	// Character zan(jyzdcs);
	// std::cout << std::endl;

	// jyzdcs.unequip(0);
	// jyzdcs.use(0, zan);
	// zan.use(0, zan);

	// std::cout << std::endl;
	// -------------- ASSIGNEMENT OPERATOR --------------

	// -------------- NORMAL USE CASE --------------
	// Character jyzdcs("Jyzdcs");
	// Ice				*ice01 = new Ice();
	// Cure			*cure01 = new Cure();
	// Ice				*ice02 = new Ice();
	// Ice				*ice03 = new Ice();

	// jyzdcs.equip(ice01);
	// jyzdcs.equip(ice02);
	// jyzdcs.equip(ice03);
	// jyzdcs.equip(cure01);
	// -------------- DESTRUCTOR --------------

	// Le destructor free en bouclant sur while inventory[i] == null
	Character 		jyzdcs("Jyzdcs");
	MateriaSource	source;
	AMateria*			materia;

	source.learnMateria(new Cure());
	source.learnMateria(new Ice());
	source.learnMateria(NULL);
	std::cout << std::endl;
	
	materia = source.createMateria("Cure");
	jyzdcs.equip(materia);
	jyzdcs.equip(materia);

	std::cout << std::endl;
	// -------------- 

	// Character jyzdcs("Jyzdcs");
	// Ice				*ice = new Ice();
	// Cure				*cure = new Cure();
	// Ice				*ice = new Ice();
	// Ice				*ice = new Ice();

	// jyzdcs.equip(ice);
	// jyzdcs.equip(cure);
	// jyzdcs.equip(cure);
	// jyzdcs.equip(cure);
	// jyzdcs.equip(cure);
	// delete ice;
	// jyzdcs.unequip(0);
	// jyzdcs.equip(cure);
	// jyzdcs.use(4, jyzdcs);
	// delete cure;
}