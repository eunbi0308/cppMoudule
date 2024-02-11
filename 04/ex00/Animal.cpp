#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called." << std::endl;
	this->type = "";
}

Animal::Animal(const Animal &)
{
	std::cout << "Animal Copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "The animal makes a sound " << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}