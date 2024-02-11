#include "Dog.hpp"

Dog::Dog()
{
	std::cout << GREEN << "Dog Default constructor called." << DEFAULT << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &) : Animal()
{
	std::cout << GREEN << "Dog Copy constructor called." << DEFAULT  << std::endl;
}

Dog &Dog::operator=(const Dog &)
{
	std::cout << GREEN << "Dog copy assignment operator called." << DEFAULT << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog Destructor called." << DEFAULT << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << GREEN << this->type << " : Woof" << DEFAULT << std::endl;
}