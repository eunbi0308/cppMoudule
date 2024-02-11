#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal Default constructor called." << std::endl;
	this->type = "";
	this->brain = new Brain();
	if (this->brain == nullptr)
		std::cerr << "Failed to allocate memory for dog's brain" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Animal Copy constructor called." << std::endl;
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &other)
	{
		if (this->brain != nullptr)
			delete this->brain;
		this->type = other.type;
		this->brain = new Brain(*other.brain);
		if (this->brain == nullptr)
			std::cerr << "Failed to allocate memory for brain" << std::endl;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal Destructor called." << std::endl;
	delete this->brain;
}

void	AAnimal::makeSound() const
{
	std::cout << "The animal makes a sound " << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->type;
}

Brain	*AAnimal::getBrain()
{
	return this->brain;	
}