#include "Fixed.hpp"

int	main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const c( Fixed( 2 ) + Fixed( 2 ) );
	// Fixed const d( Fixed( 122 ) - Fixed( 22 ) );
	// Fixed const e( Fixed( 10 ) / Fixed( 5 ) );

	// std::cout << b << "\n";
	// std::cout << c << "\n";
	// std::cout << d << "\n";
	// std::cout << e << "\n";

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}