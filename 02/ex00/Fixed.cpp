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
	// Using operator
	*this = num;
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