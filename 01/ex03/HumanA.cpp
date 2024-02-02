#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	std::cout << "HumanA " << name << "is created." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA is destroyed." << std::endl;
}

void	HumanA::attack()
{
	std::cout << GREEN << "HumanA " << this->name << "attacks with their " 
				<< weapon.getType() << DEFAULT << std::endl;
}

