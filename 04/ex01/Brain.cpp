#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE << "Brain Default constructor called." << DEFAULT << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << BLUE  << "Brain Copy constructor called." << DEFAULT << std::endl;
	for (int i = 0; i < 100; ++i)
	{
        this->ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << BLUE  << "Brain copy assignment operator called." << DEFAULT << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << BLUE  << "Brain Destructor called." << DEFAULT << std::endl;
}

size_t Brain::getIdeasArraySize() const
{
	return sizeof(ideas) / sizeof(ideas[0]);
}

void	Brain::setIdea(std::string idea, unsigned int index)
{
	if (index < this->getIdeasArraySize())
	{
		this->ideas[index] = idea;
	}
}

std::string	 Brain::getIdea(unsigned int index)
{
	return this->ideas[index];
}

