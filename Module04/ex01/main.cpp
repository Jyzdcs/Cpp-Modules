#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include "Brain.hpp"

int	main(void){
	// ------------------------------------------------ Classic Test ----------------------------------------------------------------
	// std::string arr[100];
	// std::string arr1[100];

	// arr[0] = "damn!";
	// arr[1] = "...";
	// arr[2] = "damn!";
	// arr[3] = "...";

	// for (int i = 0; arr[i] != ""; i++) {
	// 	std::cout << arr[i] << std::endl;
	// }

	// ------------------------------------------------ COPY TEST ----------------------------------------------------------------
	// Brain brain0;

	// for (int i = 0; i < 100; i++) {
	// 	brain0.setIdea("Lafeve");
	// }

	// Brain brain1(brain0);
	// std::string *ideas = brain1.getIdeas();
	// for (int i = 0; ideas[i] != ""; i++) {
	// 	std::cout << ideas[i] << " " << i << std::endl;
	// }

	// ------------------------------------------------ Operand Assign Test ----------------------------------------------------------------
	// Brain brain0;
	// Brain brain1;
	
	// for (int i = 0; i < 10; i++) {
	// 	brain0.setIdea("Lafeve");
	// };
	// for (int j = 0; j < 5; j++) {
	// 	brain1.setIdea("Elyslime");
	// };
	
	// std::cout << "\n\nBrain0 : \n";
	// std::string *ideas0 = brain0.getIdeas();
	// for (int i = 0; ideas0[i] != ""; i++) {
	// 	std::cout << ideas0[i] << " " << i << std::endl;
	// }
	
	// std::cout << "\n\nBrain1 : \n";
	// std::string *ideas1 = brain1.getIdeas();
	// for (int i = 0; ideas1[i] != ""; i++) {
	// 	std::cout << ideas1[i] << " " << i << std::endl;
	// }

	// brain0 = brain1;
	// std::cout << "\n\nBrain0 : \n";
	// ideas0 = brain0.getIdeas();
	// for (int i = 0; ideas0[i] != ""; i++) {
	// 	std::cout << ideas0[i] << " " << i << std::endl;
	// }

	// ------------------------------------------------ Deep copy test ------------------------------------------------
	// Cat *cat(new Cat());
	// cat->setIdea("Zzzzz");

	// Cat cat1(*cat);
	// std::cout << "\n";
	
	// Brain *catBrain = cat->getBrain();
	// catBrain->printIdeas();
	// std::cout << "\n";
	// delete cat;

	// std::cout << "\n";
	// catBrain->printIdeas();
	// std::cout << "\n";

	// std::cout << "\n";
	// Brain *cat1Brain = cat1.getBrain();
	// cat1Brain->printIdeas();
	// std::cout << "\n";
	// ------------------------------------------------ main test ------------------------------------------------
	// Animal *animals[6];
	// animals[0] = new Dog();
	// std::cout << "\n";
	// animals[1] = new Dog();
	// std::cout << "\n";
	// animals[2] = new Dog();
	// std::cout << "\n";
	// animals[3] = new Cat();
	// std::cout << "\n";
	// animals[4] = new Cat();
	// std::cout << "\n";
	// animals[5] = new Cat();
	// std::cout << "\n";

	// for (int i = 0; i < 6; i++) {
	// 	delete animals[i];
	// 	std::cout << "\n";
	// };
	// ------------------------------------------------ subject test ------------------------------------------------
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;
};