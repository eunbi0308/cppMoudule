#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << GREEN << "HumanA " << this->name << " is created." << DEFAULT << std::endl;
	std::cout << GREEN << "[" + weapon.getType() << "] is set." << DEFAULT << std::endl;
}

HumanA::~HumanA()
{
	std::cout << GREEN << "HumanA " << this->name << " is destroyed." << DEFAULT << std::endl;
}

void	HumanA::attack() const
{
	std::cout << GREEN << "HumanA " << this->name << " attacks with their " 
				<< "[" + weapon.getType() + "]" << DEFAULT << std::endl;
}

