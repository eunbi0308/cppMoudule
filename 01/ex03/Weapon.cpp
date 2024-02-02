#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon has been destroyed.\n";
}

std::string	Weapon::getType()
{
	return this->type;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

