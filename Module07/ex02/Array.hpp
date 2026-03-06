#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		T 						*_data;
		unsigned int	_size;

	public:
		Array() {
			std::cout << "[Array] ctor called" << std::endl;
			_data = new T[0];
		};
		Array(unsigned int n) : _size(n) {
			std::cout << "[Array] param ctor called" << std::endl;
			_data = new T[_size];
		};
		Array&	operator=(const Array& src) {
			std::cout << "[Array] assignement opereator" << std::endl;
			if (this == &src)	return *this;

			delete[] this->_data;
			std::cout << "data deleted" << std::endl;
			this->_data = new T[src._size];
			this->_size = src._size;
			for (unsigned int i = 0; i < src._size; i++) {
				this->_data[i] = src._data[i];
			}
			return *this;
		};
		T&	operator[](unsigned int idx) {
			if (idx >= _size) throw	OutOfRange();

			return _data[idx];
		};
		Array(const Array& src) {
			std::cout << "[Array] cpy ctor called" << std::endl;
			
			this->_data = new T[src._size];
			this->_size = src._size;
			for (unsigned int i = 0; i < src._size; i++) {
				this->_data[i] = src._data[i];
			}
		};
		~Array() {
			std::cout << "[Array] dtor called" << std::endl;
			delete[] _data;
		};

		unsigned int	getSize() {	return _size; };
		T							getData() {	return _data; };

		void					printDataContent() {
			for (unsigned int i = 0; i < _size; i++) {
				std::cout << _data[i] << std::endl;
			}
		};

		class OutOfRange : public std::exception {
			const char *what() const throw() {
				return "OutOfRange: Error index is outOfRange\n";
			};
		};

};

#endif