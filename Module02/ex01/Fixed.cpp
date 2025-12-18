#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
};

Fixed::Fixed(): _fixedPoint(0) {
	std::cout << "Default constructor called\n";
};

Fixed::Fixed(int const num):_fixedPoint(num << _fractionalBits) {};

Fixed::Fixed(float const num): _fixedPoint(roundf(num * 256)) {};

Fixed::Fixed(Fixed const& src): _fixedPoint(src._fixedPoint) {
	std::cout << "Copy constructor called\n";
};

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs) {
		this->_fixedPoint = rhs._fixedPoint;
	}
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
};

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return _fixedPoint;
};

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_fixedPoint = raw;
};

int		Fixed::toInt(void) const {
	return _fixedPoint >> _fractionalBits;
};

float	Fixed::toFloat(void) const {
	return _fixedPoint / 256.0f;
};

