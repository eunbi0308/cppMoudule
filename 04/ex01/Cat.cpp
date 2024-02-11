#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << PURPLE << "Cat Default constructor called." << DEFAULT << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << PURPLE << "Cat Copy constructor called." << DEFAULT << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << PURPLE << "Cat copy assignment operator called." << DEFAULT << std::endl;

	if (this != &other)
	{
		if (this->brain != nullptr)
			delete this->brain;
		this->type = other.type;
		this->brain = new Brain(*other.brain);
		if (this->brain == nullptr)
			std::cerr << "Failed to allocate memory for cat's brain" << std::endl;
	}
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
