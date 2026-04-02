#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class Rpn {
	private:
		std::stack<int>	_stack;
		std::string			_rpn;

		int	getOperationResult(int first, int second, char operand);

	public:
		Rpn(std::string rpn);
		~Rpn();

		void	calcul();

		class ErrorRpnException : public std::exception {
			const char* what() const throw();
		};
};

#endif