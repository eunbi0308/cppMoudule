#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " has been created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << YELLOW << this->name + ":";
	std::cout << "BraiiiiiiinnnzzzZ..." << DEFAULT << std::endl;
}