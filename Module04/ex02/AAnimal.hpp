#ifndef AANIMAL_HPP
# define AANIMAL_HPP
#include <iostream>
#include <string>

class AAnimal {
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		AAnimal& operator=(const AAnimal &src);
		virtual ~AAnimal();

		std::string		getType();

		virtual void	makeSound() = 0;
};

#endif