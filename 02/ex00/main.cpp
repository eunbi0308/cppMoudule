#include "Fixed.hpp"

int main( void ) 
{
	Fixed a; // Default
	Fixed b( a ); // Copy constructor
	Fixed c; // Default
	
	c = b; // Copy assignment operator overload(override)

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	/***** test *****/
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << &c << std::endl;

	return 0;
}