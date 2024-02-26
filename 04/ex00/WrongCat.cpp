#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << RED << "WrongCat Default constructor called." << DEFAULT << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &) : WrongAnimal()
{
	std::cout << RED << "WrongCat Copy constructor called." << DEFAULT << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &)
{
	std::cout << RED << "WrongCat copy assignment operator called." << DEFAULT << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat Destructor called." << DEFAULT << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << RED << this->type << " : Meowooffff" << DEFAULT << std::endl;
}