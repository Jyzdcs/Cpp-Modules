#include <iostream>
#include "iter.hpp"

void	multiply(int &n) {
	n *= n;
}

int main() {
	int arr[6] = {0, 1, 2, 3, 4, 5};
	int const len = 6;

	iter(arr, len, &multiply);
	std::cout << arr[0] << std::endl;
	std::cout << arr[1] << std::endl;
	std::cout << arr[2] << std::endl;
	std::cout << arr[3] << std::endl;
	std::cout << arr[4] << std::endl;
	std::cout << arr[5] << std::endl;
};