#include "Animal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default constructor called." << std::endl;
	this->type = "";
}

AAnimal::AAnimal(const AAnimal &)
{
	std::cout << "AAnimal Copy constructor called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &)
{
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called." << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "The animal makes a sound " << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->type;
}