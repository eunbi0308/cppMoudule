#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor called." << std::endl;
	this->type = "Wrong";
}

WrongAnimal::WrongAnimal(const WrongAnimal &)
{
	std::cout << "WrongAnimal Copy constructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &)
{
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << YELLOW << "The WrongAnimal makes a sound " << DEFAULT << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}