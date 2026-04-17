#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <exception>

class Span {
	private:
		std::vector<int>	_arr;
		unsigned int			_size_max;

	public:
		Span(unsigned int N);
		Span& operator=(const Span &src);
		Span(const Span &src);
		~Span();

		void	addNumber(int nb);
		void	addNumbers(std::vector<int> l);
		void	display();
		void	addRandomNumbers(unsigned int quantity);
		
		int	shortestSpan();
		int	longestSpan();

		class MaxCapacityException : public std::exception {
			const char* what() const throw();
		};
};

#endif