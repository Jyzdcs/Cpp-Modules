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

		int		getRawBits(void) const;
		
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);


#endif