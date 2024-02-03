#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << YELLOW << "HumanB " << this->name << " is created." << DEFAULT  << std::endl;
}

HumanB::~HumanB()
{
	std::cout << YELLOW << "HumanB " << this->name << " is destroyed." << DEFAULT  << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << YELLOW << "[" + this->weapon->getType() + "]" << " is set." << DEFAULT << std::endl;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << YELLOW << "HumanB " << this->name << " attacks with their "
			 << "[" + this->weapon->getType() + "]" << DEFAULT << std::endl;
	else
		std::cout << YELLOW << "HumanB " << this->name << " attacks without a weapon."
			 << DEFAULT << std::endl;
}
