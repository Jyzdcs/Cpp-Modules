#include "Array.hpp"

int	main() {
	Array<int>	*arr00 = new Array<int>(3);
	Array<int>	*arr01 = new Array<int>(3);

	try {
		int a = 1;
		int b = 2;
		int c = 3;

		int d = 4;
		int e = 5;
		int f = 6;

		arr00->setData(a);
		arr00->setData(b);
		arr00->setData(c);

		arr01->setData(d);
		arr01->setData(e);
		arr01->setData(f);


		arr00->printDataContent();
		std::cout << std::endl;
		arr01->printDataContent();
		std::cout << std::endl;
		*arr01 = *arr00;
		arr01->printDataContent();

		Array<int>	arr02(*arr00);
		arr02.printDataContent();
	} catch (std::exception& err) {
		std::cout << err.what();
	}

	delete arr00;
	delete arr01;
}