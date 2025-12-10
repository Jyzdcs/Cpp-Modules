#ifndef HUMANB_H
#define HUMANB_H
#	include <iostream>
#	include "Weapon.h"

class HumanB {
	private:
		std::string _name;
		Weapon* 			_weapon;

	public:
		HumanB(std::string name);

		void	attack();
		void	setWeapon(Weapon& weapon);
};

#endif