#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	type;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria& src);
		AMateria& operator=(const AMateria& src);
		virtual ~AMateria();

		std::string const&	getType();

		virtual AMateria*	clone() const = 0;
		virtual void			use(ICharacter& target);

};

#endif