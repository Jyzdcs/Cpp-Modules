#include "Span.hpp"

Span::Span(unsigned int N) : _arr(0), _size_max(N) {
	std::cout << "[Span] ctor called" << std::endl;
};

Span& Span::operator=(const Span &src) {
	if (this == &src)	return *this;

	this->_size_max = src._size_max;
	this->_arr = src._arr;
	return *this;
};

Span::Span(const Span &src) {
	std::cout << "[Span] ctor cpy called" << std::endl;
	*this = src;
};

Span::~Span() {
	std::cout << "[Span] dtor called" << std::endl;
};

void	Span::addNumber(int nb) {
	if (_arr.size() + 1 > _size_max) {
		throw Span::MaxCapacityException();
	}
	_arr.push_back(nb);
};

void	Span::addNumbers(std::vector<int> l) {
	if (l.size() > _size_max - (_arr.size() - 1))
		throw Span::MaxCapacityException();
	_arr.insert(_arr.end(), l.begin(), l.end());
};

void	Span::display() {
	for (unsigned int i = 0; i < _arr.size(); i++) {
		if (i + 1 == _arr.size()) {
			std::cout << _arr[i] << std::endl;
			return ;
		}
		std::cout << _arr[i] << ", ";
	}
}

void Span::addRandomNumbers(unsigned int quantity) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		while (quantity > 0) {
			int randomNum = std::rand() - RAND_MAX / 2;
			this->addNumber(randomNum);
			std::cout << "Random number added: " << randomNum << std::endl;
			quantity--;
		}
}

int	Span::shortestSpan() {
	int shortestSpan;

	sort(_arr.begin(), _arr.end());
	shortestSpan = _arr[1] - _arr[0];
	for (unsigned int i = 0; i < _arr.size() - 1; i++) {
		shortestSpan = (_arr[i + 1] - _arr[i]) < shortestSpan ? _arr[i + 1] - _arr[i] : shortestSpan;
	}
	return shortestSpan;
};

int	Span::longestSpan() {
	sort(_arr.begin(), _arr.end());
	return _arr[_arr.size() - 1] - _arr[0];
};

const char* Span::MaxCapacityException::what() const throw() {
	return "ErrorOfContext: You reached the max capacity";
};