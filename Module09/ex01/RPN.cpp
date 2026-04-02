#include "RPN.hpp"

Rpn::Rpn(std::string rpn) : _rpn(rpn) {};

Rpn::~Rpn() {};

int	Rpn::getOperationResult(int first, int second, char operand) {
	switch (operand) {
		case '+':
			return first + second;
		case '-':
			return first - second;
		case '/':
			if (second == 0)
				throw ErrorRpnException();
			return first / second;
		case '*':
			return first * second;
		default:
			throw ErrorRpnException();
	}
};

void	Rpn::calcul() {
	for (size_t i = 0; i < _rpn.size(); i++) {
		if (_rpn[i] == ' ')	continue;
		if (std::isdigit(_rpn[i])) {
			if (atoi(_rpn.c_str()) > 9)
				throw ErrorRpnException();
			_stack.push(_rpn[i] - '0');
		} else {
			if (_stack.size() != 2) {
				throw ErrorRpnException();
			}
			int secondNum = _stack.top();
			_stack.pop();
			int firstNum = _stack.top();
			_stack.pop();
			_stack.push(getOperationResult(firstNum, secondNum, _rpn[i]));
		}
	}
	if (_stack.size() != 1)
		throw ErrorRpnException();
	std::cout << "Top: " << _stack.top() << std::endl;
};

const char* Rpn::ErrorRpnException::what() const throw() {
	return "Error";
};