#include <iostream>
#include "iter.hpp"

void	multiply(int &n) {
	n *= n;
}

// void	multiply(const char &c) {
// 	std::cout << static_cast<char>(c + 1) << std::endl;
// }

void	addition(char& n) {
	n = n + 1;
}

int main() {
	// char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int arr[6] = {0, 1, 2, 3, 4, 5};
	int const len = 6;

	// iter<char*, const int, void (const char &)>(arr, len, &multiply);
	iter(arr, len, multiply);
	std::cout << arr[0] << std::endl;
	std::cout << arr[1] << std::endl;
	std::cout << arr[2] << std::endl;
	std::cout << arr[3] << std::endl;
	std::cout << arr[4] << std::endl;
	std::cout << arr[5] << std::endl;
};