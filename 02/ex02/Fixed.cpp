#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << GREY << "Default costructor called" << DEFAULT << std::endl; 
	this->fixedPointNumber = 0;
}

Fixed::~Fixed()
{
	// std::cout << GREY << "Destructor called" << DEFAULT << std::endl; 
}

Fixed::Fixed(const Fixed &num)
{
	// std::cout << YELLOW << "Copy constructor called" << DEFAULT << std::endl;
	*this = num;
}

Fixed::Fixed(const int intNumber)
{
	// std::cout << PURPLE << "Int constructor called" << DEFAULT << std::endl;
	this->fixedPointNumber = intNumber << fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
	// std::cout << PURPLE << "Float constructor called" << DEFAULT << std::endl;
								// floatNumber * 2^3(= 256);
	this->fixedPointNumber = roundf(floatNumber * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &num)
{
	// std::cout << YELLOW << "Copy assignment operator called" << DEFAULT << std::endl;
	if (this != &num)
		this->fixedPointNumber = num.getRawBits();
	return *this;
}

/*** Functions ***/

int	Fixed::getRawBits(void) const
{
	// std::cout << GREEN << "getRawBits member function called" << DEFAULT << std::endl;
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
	output << fixedPoint.toFloat();
	return output;
}

/** Comparison operators **/
bool Fixed::operator>(const Fixed &num) const
{
	return this->getRawBits() > num.getRawBits();
}

bool Fixed::operator<(const Fixed &num) const
{
	return this->getRawBits() < num.getRawBits();
}

bool Fixed::operator>=(const Fixed &num) const
{
	return this->getRawBits() >= num.getRawBits();
}

bool Fixed::operator<=(const Fixed &num) const
{
	return this->getRawBits() <= num.getRawBits();
}

bool Fixed::operator==(const Fixed &num) const
{
	return this->getRawBits() == num.getRawBits();
}

bool Fixed::operator!=(const Fixed &num) const
{
	return this->getRawBits() != num.getRawBits();
}

/** Arithmetic operators **/
Fixed Fixed::operator+(const Fixed &num) const
{
	return Fixed(this->toFloat() + num.toFloat());
}

Fixed Fixed::operator-(const Fixed &num) const
{
	return Fixed(this->toFloat() - num.toFloat());
}

Fixed Fixed::operator*(const Fixed &num) const
{
	return Fixed(this->toFloat() * num.toFloat());
}

Fixed Fixed::operator/(const Fixed &num) const
{
	return Fixed(this->toFloat() / num.toFloat());
}

/** Increment operators**/
// postfix
/*
*	The postfix increment operator is defined to return the "original" value
*	and increment the object. Therefore, a temporary object is necessary to ensure
*	that the original value of the object.
*/
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->fixedPointNumber;
	return tmp;
}
// prefix
Fixed Fixed::operator++(void)
{
	++this->fixedPointNumber;
	return *this;
}

/** Decrement operators **/
// postfix
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->fixedPointNumber;
	return tmp;
}
// prefix
Fixed Fixed::operator--(void)
{
	--this->fixedPointNumber;
	return *this;
}

/** Static functions **/
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() <= b.getRawBits()) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() <= b.getRawBits()) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() >= b.getRawBits()) ? a : b;
}

const	Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() >= b.getRawBits()) ? a : b;
}

