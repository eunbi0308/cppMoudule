#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Weapon has been created.\n";
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
	std::cout << "Type [" + this->type + "]" <<  " is set." << std::endl;
}

