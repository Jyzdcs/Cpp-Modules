#include "Span.hpp"

int main(void) {
	try {
		Span span(20);

		span.addNumber(133);
		span.addNumber(23);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		int arr[] = {11, 23, 45, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> v(arr, arr + n);
		span.addNumbers(v);
		span.display();
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (std::exception& err) {
		std::cout << err.what();
	}

	// try {
	// 	Span sp = Span(7);
	// 	Span sp1(3);
	// 	sp.addNumber(6);
	// 	sp.addNumber(3);
	// 	sp.addNumber(17);
	// 	sp.addNumber(9);
	// 	sp.addNumber(11);

	// 	sp1 = sp;
	// 	sp1.addNumber(545);
	// 	Span sp2 = Span(sp1);
	// 	sp2.addNumber(900);
	// 	sp1.display();
	// 	sp.display();
	// 	sp2.display();
	// } catch (std::exception& err) {
	// 	std::cout << err.what();
	// }
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
}