#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _learned[4];
		int				_idx;
		int				getLearnedNbr();
		bool 			isUniqueMateria(AMateria* materia);

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(const MateriaSource& src);
		~MateriaSource();

		void				learnMateria(AMateria*);
		AMateria*		createMateria(std::string const& type);
};

#endif