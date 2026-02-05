#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure {
	public:
		AMateria*	clone() const;
		void			use(ICharacter& target);
};

#endif