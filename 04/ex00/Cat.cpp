#include "Cat.hpp"

Cat::Cat()
{
	std::cout << PURPLE << "Cat Default constructor called." << DEFAULT << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &) : AAnimal()
{
	std::cout << PURPLE << "Cat Copy constructor called." << DEFAULT << std::endl;
}

Cat &Cat::operator=(const Cat &)
{
	std::cout << PURPLE << "Cat copy assignment operator called." << DEFAULT << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << PURPLE << "Cat Destructor called." << DEFAULT << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << this->type << " : Meow Meow" << DEFAULT << std::endl;
}