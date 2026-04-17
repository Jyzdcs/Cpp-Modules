#include "easyfind.hpp"

int main() {
	std::vector<int> v1;
   
	v1.push_back(10);
	v1.push_back(-5);
	v1.push_back(232);
	v1.push_back(42);
	v1.push_back(-42);
	// for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); it++) {
	// 	std::cout << *it << std::endl;
	// };
	std::cout << easyfind(v1, -42) << std::endl;
	std::cout << easyfind(v1, -54) << std::endl;
}