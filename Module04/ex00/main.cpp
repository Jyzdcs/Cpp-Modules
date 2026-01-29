#include "Cat.hpp"
#include "Dog.hpp"

int	main(void){
	// Dog dog1;
	// Cat cat1;

	// dog1.makeSound();
	// cat1.makeSound();

	// std::cout << "Type of dog1 is " << dog1.getType() << std::endl;
	// std::cout << "Type of cat1 is " << cat1.getType() << std::endl;

	Animal *animal0 = new Animal();
	Animal *animal1 = new Dog();
	Animal *animal2 = new Cat();

	animal0->makeSound();
	animal1->makeSound();
	animal2->makeSound();

	std::cout << "Type of animal0 is " << animal0->getType() << std::endl;
	std::cout << "Type of animal1 is " << animal1->getType() << std::endl;
	std::cout << "Type of animal2 is " << animal2->getType() << std::endl;

	delete animal0;
	delete animal1;
	delete animal2;
};