#ifndef ITER_HPP
#define ITER_HPP

template <typename A, typename F>
void	iter(A* adr, int const len, void (*fct)(F)) {
	for (int i = 0; i < len; i++) {
		fct(adr[i]);
	};
};


#endif