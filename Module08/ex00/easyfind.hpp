#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
int	easyfind(T &c, int num) {
	typename T::iterator it = std::find(c.begin(), c.end(), num);
	if (it == c.end()) {
		std::cout << "value isnt in the container" << std::endl;
		return -1;
	}
	std::cout << "found the value " << *it << " in the container at index " << std::distance(c.begin(), it) << std::endl;
	return *it;
};

#endif