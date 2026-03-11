#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
int	easyfind(T &c, int num) {
	for (size_t i = 0; i < c.size(); i++) {
		if (num == c[i])	return i;
	}
	return -1;
};

#endif