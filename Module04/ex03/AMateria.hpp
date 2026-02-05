#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	type;

	public:
		AMateria(std::string const &type);
		// [...]

		std::string const&	getType(); // return materia type 

		virtual AMateria*	clone() const = 0;
		virtual void			use(ICharacter& target);

};

#endif