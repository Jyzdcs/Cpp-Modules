#include "easyfind.hpp"

int main() {
	std::vector<int> v1;
   
	v1.push_back(10);
	v1.push_back(-5);
	v1.push_back(232);
	v1.push_back(42);
	v1.push_back(-42);
	std::cout << easyfind(v1, -42) << std::endl;
}