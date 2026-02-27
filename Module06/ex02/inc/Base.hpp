#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
// class A;
// class B;
// class C;

class Base {
	private:
		int	randomNbrInRange(int, int);

	public:
		Base();
		Base(const Base&);
		Base& operator=(const Base&);
		virtual ~Base();

		Base*	generate(void);

		void	identify(Base* p);
		void	identify(Base& p);
};

#endif