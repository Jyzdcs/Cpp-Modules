#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat& operator=(const WrongCat &src);
		virtual ~WrongCat();

		void makeSound();
};

#endif