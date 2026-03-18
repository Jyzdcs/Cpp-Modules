#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
class MutantStack {
	private:
		std::vector<T>	_mutantStack;

	public:
		MutantStack() : _mutantStack(0) {
			std::cout << "[MutantStack] ctor called\n";
		};
		MutantStack&	operator=(const MutantStack& src) {
			if (this == &src)	return *this;

			this->_mutantStack = src._mutantStack;
			return *this;
		};
		MutantStack(const MutantStack& src) {
			*this = src;
		};
		~MutantStack() {
			std::cout << "[MutantStack] dtor called\n";
		};

		typedef	typename std::vector<T>::iterator	iterator;

		bool		empty() const {
			return _mutantStack.empty();
		};
		size_t	size() const {
			return _mutantStack.size();
		};
		T&			top() {
			return _mutantStack.back();
		};
		
		void	push(const T& val) {
			_mutantStack.push_back(val);
		};
		void	pop() {
			_mutantStack.pop_back();
		};
		void	swap(MutantStack& s) {
			_mutantStack.swap(s._mutantStack);
		};
		iterator	begin() {
			return _mutantStack.begin();
		};
		iterator	end() {
			return _mutantStack.end();
		};
};

#endif