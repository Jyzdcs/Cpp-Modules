#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac == 2)
	{
		ScalarConverter *test = NULL;
		test->convert(av[1]);
	} else {
		return 1;
	}
}