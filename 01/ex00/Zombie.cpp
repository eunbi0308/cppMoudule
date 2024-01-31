#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << YELLOW << this->name + ":";
	std::cout << "BraiiiiiiinnnzzzZ..." << DEFAULT << std::endl;
}