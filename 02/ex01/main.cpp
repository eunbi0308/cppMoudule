#include "Fixed.hpp"

int main( void ) 
{
	{
		// Left bit shifting by 8 bits (the fractionalBits is 8
		// without "<<" overload operator. So float point number cannot be printed.
		std::cout << std::endl;
		std::cout << RED << "----- Rawbits" << DEFAULT << std::endl;
		Fixed		a; // Default
		Fixed const b( 10 ); // Int constructor
		Fixed const c( 42.42f ); // Flost constructor
		Fixed const d( b ); // Copy constructor;

		a = Fixed( 1234.4321f ); // Operator

		std::cout << "a is " << a.getRawBits() << std::endl;
		std::cout << "b is " << b.getRawBits() << std::endl;
		std::cout << "c is " << c.getRawBits() << std::endl;
		std::cout << "d is " << d.getRawBits() << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "----- Print float and integer" << DEFAULT << std::endl;

		Fixed		a; // Default
		Fixed const b( 10 ); // Int constructor
		Fixed const c( 42.42f ); // Flost constructor
		Fixed const d( b ); // Copy constructor;

		a = Fixed( 1234.4321f ); // Operator

		// overload operator is called.
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "----- Only float" << DEFAULT << std::endl;

		Fixed		a; // Default
		Fixed const b( 10 ); // Int constructor
		Fixed const c( 42.42f ); // Flost constructor
		Fixed const d( b ); // Copy constructor;

		a = Fixed( 1234.4321f ); // Operator

		std::cout << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "----- Max/Min integer value" << DEFAULT << std::endl;

		// 32 bit
		Fixed	max(INT32_MAX);
		Fixed	min(INT32_MIN);

		std::cout << "max is " << max << std::endl;
		std::cout << "min is " << min << std::endl;
	}
	return 0;
}