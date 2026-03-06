#include "Array.hpp"

int	main() {
	try {
		Array<int>	arr04(3);

		arr04[0] = 4;
		arr04[1] = 2;
		arr04[2] = 5;
		std::cout << arr04[1] << std::endl;
		std::cout << arr04[2] << std::endl;
		std::cout << arr04[0] << std::endl;
	} catch (std::exception& err) {
		std::cout << err.what();
	}
	
	// Array<int>	*arr00 = new Array<int>(3);
	// Array<int>	*arr01 = new Array<int>(3);

	// try {
	// 	int a = 1;
	// 	int b = 2;
	// 	int c = 3;

	// 	int d = 4;
	// 	int e = 5;
	// 	int f = 6;

	// 	arr00[0] = a;
	// 	arr00[1] = b;
	// 	arr00[2] = c;

	// 	arr01[0] = d;
	// 	arr01[1] = e;
	// 	arr01[2] = f;


	// 	arr00->printDataContent();
	// 	std::cout << std::endl;
	// 	arr01->printDataContent();
	// 	std::cout << std::endl;
	// 	*arr01 = *arr00;
	// 	arr01->printDataContent();

	// 	Array<int>	arr02(*arr00);
	// 	arr02.printDataContent();
	// } catch (std::exception& err) {
	// 	std::cout << err.what();
	// }

	// delete arr00;
	// delete arr01;
}