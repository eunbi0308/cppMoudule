#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	{
		std::cout << std::endl;
		std::cout << RED << "Basic Test" << DEFAULT << std::endl;
		Fixed		a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{		
		std::cout << std::endl;
		std::cout << RED << "Comparison Test" << DEFAULT << std::endl;
		Fixed	a(10);
		Fixed	b(10.01f);

		std::cout << "a < b	: " << (a < b) << std::endl;
		std::cout << "a <= b	: " << (a <= b) << std::endl;
		std::cout << "a > b	: " << (a > b) << std::endl;
		std::cout << "a >= b	: " << (a >= b) << std::endl;
		std::cout << "a == b	: " << (a == b) << std::endl;
		std::cout << "a != b	: " << (a != b) << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Arithmetic Test" << DEFAULT << std::endl;
		Fixed		a(0.25f);
		Fixed		b(2);

		std::cout << a << std::endl;
		std::cout << a + a << std::endl;
		std::cout << a - a << std::endl;
		std::cout << a * a << std::endl;
		std::cout << a / a << std::endl;
		std::cout << std::endl;

		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
		std::cout << std::endl;

		std::cout << a + 0.25f << std::endl;
		std::cout << a - 0.25f << std::endl;
		std::cout << a * 0.25f << std::endl;
		std::cout << a / 0.25f << std::endl;
		std::cout << std::endl;

		std::cout << a + 1 << std::endl;
		std::cout << a - 1 << std::endl;
		std::cout << a * 1 << std::endl;
		std::cout << a / 1 << std::endl;
		std::cout << std::endl;

		std::cout << a + 0 << std::endl;
		std::cout << a - 0 << std::endl;
		std::cout << a * 0 << std::endl;
		std::cout << a / 0 << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Extra Arithmetic with Float Test" << DEFAULT << std::endl;
		Fixed		a(134635.246f);

		std::cout << a << std::endl;
		a = a + Fixed(1.0f);
		std::cout << a << std::endl;
		int n = 256;
		while (n--)
			a = a - Fixed((1.0f/256.0f));
		std::cout << a << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Increment/Decrement Test" << DEFAULT << std::endl;
		Fixed	a(10);
		Fixed	b(10);
		int		i = 10;
		float	f = 0.001;

		/*
		*	In a fixed-point representation with 8 fractional bits,
		*	incrementing the integer value by 1, what is the smallest fractionalBits
		*	that is incrementable, would be equivalent 
		*	to adding 2^-8 (0.00390625) to the fixed-point number.
		*/
		std::cout << "++a	: " << ++a << std::endl;
		std::cout << "b	: " << b << std::endl;
		std::cout << "b++	: " << b++ << std::endl;
		std::cout << "b	: " << b << std::endl;
		std::cout << "++i	: " << ++i << std::endl;
		std::cout << "++f	: " << ++f << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "MIN/MAX Test" << DEFAULT << std::endl;
		Fixed	a(10);
		Fixed	b(10.01f);
		int		c = 11;
		int		d = 10;

		std::cout << "min(a, b) : " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) : " << Fixed::max(a, b) << std::endl;
		std::cout << "min(b, c) : " << Fixed::min(b, c) << std::endl;
		std::cout << "max(b, c) : " << Fixed::max(b, c) << std::endl;
		std::cout << "min(a, d) : " << Fixed::min(a, d) << std::endl;
		std::cout << "max(a, d) : " << Fixed::max(a, d) << std::endl;
	}
	return 0;
}