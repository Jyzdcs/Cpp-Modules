#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
	private:
		int 							_fixedPoint;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(Fixed const& src);
		Fixed& operator=(Fixed const& rhs);
		~Fixed();

    bool operator>(Fixed const& other) const ;
    bool operator<(Fixed const& other) const ;
    bool operator>=(Fixed const& other) const ;
    bool operator<=(Fixed const& other) const ;
    bool operator==(Fixed const& other) const ;
    bool operator!=(Fixed const& other) const ;

		Fixed operator+(Fixed const& other) const ;
		Fixed operator-(Fixed const& other) const ;
		Fixed operator*(Fixed const& other) const ;
		Fixed operator/(Fixed const& other) const ;
		
		// Post - incre/decre
		Fixed operator++(int);
		Fixed operator--(int);
		// Pre - incre/decre
		Fixed& operator++();
		Fixed& operator--();

		int		getRawBits(void) const;
		
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed& min(Fixed& fixedOne, Fixed& fixedTwo);
		static Fixed& max(Fixed& fixedOne, Fixed& fixedTwo);
		static const Fixed& min(const Fixed& fixedOne, const Fixed& fixedTwo);
		static const Fixed& max(const Fixed& fixedOne, const Fixed& fixedTwo);
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);


#endif