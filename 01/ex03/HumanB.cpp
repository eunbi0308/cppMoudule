#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << "HumanB " << this->name << " is created." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->name << " is destroyed." << std::endl;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << YELLOW << "HumanB " << this->name << "attacks without "
			 << this->weapon << DEFAULT << std::endl;
	else
		std::cout << YELLOW << "HumanB " << this->name << "attacks without a weapon."
			 << DEFAULT << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}