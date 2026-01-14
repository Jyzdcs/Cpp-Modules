#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0) {
	std::cout << "Default constructor called\n";
};

Fixed::Fixed(int const num):_fixedPoint(num << _fractionalBits) {
	std::cout << "Int constructor called\n";
};

Fixed::Fixed(float const num): _fixedPoint(roundf(num * 256)) {
	std::cout << "Float constructor called\n";
};

Fixed::Fixed(Fixed const& src): _fixedPoint(src._fixedPoint) {
	std::cout << "Copy constructor called\n";
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
};

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs) {
		this->_fixedPoint = rhs._fixedPoint;
	}
	return *this;
};

bool Fixed::operator>(Fixed const& other) const {
	return this->_fixedPoint > other._fixedPoint;
};

bool Fixed::operator<(Fixed const& other) const {
	return this->_fixedPoint < other._fixedPoint;
};

bool Fixed::operator>=(Fixed const& other) const {
	return this->_fixedPoint >= other._fixedPoint;
};

bool Fixed::operator<=(Fixed const& other) const {
	return this->_fixedPoint <= other._fixedPoint;
};

bool Fixed::operator==(Fixed const& other) const {
	return this->_fixedPoint == other._fixedPoint;
};

bool Fixed::operator!=(Fixed const& other) const {
	return this->_fixedPoint != other._fixedPoint;
};

Fixed Fixed::operator+(Fixed const& other) const {
	Fixed res;

	res.setRawBits(this->_fixedPoint + other._fixedPoint);
	return (res);
};

Fixed Fixed::operator-(Fixed const& other) const {
	Fixed res;

	res.setRawBits(this->_fixedPoint - other._fixedPoint);
	return (res);
};

Fixed Fixed::operator*(Fixed const& other) const {
	Fixed res;

	res.setRawBits((this->_fixedPoint * other._fixedPoint) >> _fractionalBits);
	return (res);
};

Fixed Fixed::operator/(Fixed const& other) const {
	Fixed res;

	res.setRawBits((this->_fixedPoint << _fractionalBits ) / other._fixedPoint);
	return (res);
};

// Post - incre/decre
Fixed Fixed::operator++(int) {
	Fixed old(*this);
	_fixedPoint++;
	return old;
};

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	_fixedPoint--;
	return old;
};

// Pre - incre/decre
Fixed& Fixed::operator++() {
	_fixedPoint++;
	return *this;
};

Fixed& Fixed::operator--() {
	_fixedPoint--;
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

Fixed& Fixed::min(Fixed& fixedOne, Fixed& fixedTwo) {
	return (fixedOne > fixedTwo) ? fixedTwo : fixedOne;
};

Fixed& Fixed::max(Fixed& fixedOne, Fixed& fixedTwo) {
	return (fixedOne > fixedTwo) ? fixedOne : fixedTwo;
};

const Fixed& Fixed::min(const Fixed& fixedOne, const Fixed& fixedTwo) {
	return (fixedOne > fixedTwo) ? fixedTwo : fixedOne;
};

const Fixed& Fixed::max(const Fixed& fixedOne, const Fixed& fixedTwo) {
	return (fixedOne > fixedTwo) ? fixedOne : fixedTwo;
};

