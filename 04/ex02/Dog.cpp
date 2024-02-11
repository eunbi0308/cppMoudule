#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << GREEN << "Dog Default constructor called." << DEFAULT << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other) : AAnimal()
{
	std::cout << GREEN << "Dog Copy constructor called." << DEFAULT  << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << GREEN << "Dog copy assignment operator called." << DEFAULT << std::endl;
	
	if (this != &other)
	{
		if (this->brain != nullptr)
			delete this->brain;
		this->type = other.type;
		this->brain = new Brain(*other.brain);
		 if (this->brain == nullptr)
		 	std::cerr << "Failed to allocate memory for dog's brain" << std::endl;
	}
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
