#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default costructor called" << std::endl; 
	this->fixedPointNumber = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(const Fixed &num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed::Fixed(const int intNumber)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = intNumber << fractionalBits;
}

/*	
*	in IEEE 754, for floating-point number, Single(32 bits) and
*	Double Precision(64 bits) are commonly used formats. 
*
*	The multiplication is necessary to scale the floating-point number 
*	by a power of 2 to account for the fractional bits.
*	To convert floating-point to a fixed-point with 8 fractional bits, 
*	multiply it by 2^8 (which is 256).
*	(1 << fractionalBits) is a bitwise left shift operation, 
*	which effectively computes 2^fractionalBits.
*	When the binary point is shifted to left by a 1 bit position,
*	the exponent will be increased by 1.
*/
Fixed::Fixed(const float floatNumber)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = roundf(floatNumber * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &num)
		this->fixedPointNumber = num.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointNumber;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
}

int	Fixed::toInt(void)	const
{
	return this->fixedPointNumber >> fractionalBits;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPointNumber / (float)(1 << fractionalBits));
}
