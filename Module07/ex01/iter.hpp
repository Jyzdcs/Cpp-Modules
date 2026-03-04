#ifndef ITER_HPP
#define ITER_HPP

template <typename A, typename L, typename F>
void	iter(A adr, L const len, F *fct) {
	for (int i = 0; i < len; i++) {
		fct(adr[i]);
	};
};


#endif