#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

void	Zombie::announceOfCreation()
{
	std::cout << this->name << " has been created." << std::endl;
}

void	Zombie::announce()
{
	std::cout << YELLOW << this->name + ":";
	std::cout << "BraiiiiiiinnnzzzZ..." << DEFAULT << std::endl;
}

void	Zombie::giveName(std::string name)
{
	this->name = name;
}