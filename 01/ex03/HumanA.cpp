#include "HumanA.hpp"

void	HumanA::attack()
{
	std::string weapon = getType();
	std::cout << GREEN << this->name << "attacks with their " << weapon;
}