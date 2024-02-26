#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called." << std::endl;
	this->type = "";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy constructor called." << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;
}

void	Animal::makeSound() const {}

std::string	Animal::getType() const
{
	return this->type;
}
