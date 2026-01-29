#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal& operator=(const WrongAnimal &src);
		virtual ~WrongAnimal();

		std::string		getType();

		void	makeSound();
};

#endif