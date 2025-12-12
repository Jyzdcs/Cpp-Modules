#ifndef HUMANA_H
#define HUMANA_H
#include <string>
#include "Weapon.h"

class HumanA {
	private:
		std::string _name;
		Weapon& 			_weapon;

	public:
		HumanA(std::string _name, Weapon& weapon);

		void	attack();
};

#endif