#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREY << "Default costructor called" << DEFAULT << std::endl; 
	this->fixedPointNumber = 0;
}

Fixed::~Fixed()
{
	std::cout << GREY << "Destructor called" << DEFAULT << std::endl; 
}

Fixed::Fixed(const Fixed &num)
{
	std::cout << YELLOW << "Copy constructor called" << DEFAULT << std::endl;
	*this = num;
}

/*
*	A constructor that takes a constant integer as a parameter.
*	It converts it to the corresponding fixed-point value.
*/
Fixed::Fixed(const int intNumber)
{
	std::cout << PURPLE << "Int constructor called" << DEFAULT << std::endl;
	// Making 8 bits of space to express as a fixed point number.
	this->fixedPointNumber = intNumber << fractionalBits;
}

/*	
*	A constructor that takes a constant floating-point number as a parameter.
*	in IEEE 754, for floating-point number, Single(32 bits) and
*	Double Precision(64 bits) are commonly used formats. 
*
*	The multiplication is necessary to scale the floating-point number 
*	by a power of 2 to account for the fractional bits.
*	To convert floating-point to a fixed-point with 8 fractional bits, 
*	multiply it by 2^8 (which is 256).
*	(1 << fractionalBits) is a bitwise left shift operation, 
*	which effectively computes 2^fractionalBits.
*	To consider and process the bit itself as an integer, 
*	not to convert a real number into an integer
*	
*	1 << 8 == 256
*/
Fixed::Fixed(const float floatNumber)
{
	std::cout << PURPLE << "Float constructor called" << DEFAULT << std::endl;
								// floatNumber * 2^3(= 256);
	this->fixedPointNumber = roundf(floatNumber * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &num)
{
	std::cout << YELLOW << "Copy assignment operator called" << DEFAULT << std::endl;
	if (this != &num)
		this->fixedPointNumber = num.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << GREEN << "getRawBits member function called" << DEFAULT << std::endl;
	return this->fixedPointNumber;
}

// It converts the fixed-point value to an integer value.
int	Fixed::toInt(void)	const
{
	// It's same as  fixedPointNumber / 2^3 (= 256)
	return this->fixedPointNumber >> fractionalBits;
}

// It converts the fixed-point value to a floating-point value.
float	Fixed::toFloat(void) const
{
	// It's same as  (float)fixedPointNumber / 2^3 (= 256)
	return ((float)this->fixedPointNumber / (float)(1 << fractionalBits));
}

// It inserts a floating-point representation of the fixed-point number into the output stream object
std::ostream& operator<<(std::ostream& output, const Fixed& fixedPoint)
{
	output << static_cast<int64_t>(fixedPoint.toFloat());
	return output;
}
