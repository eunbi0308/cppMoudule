#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << GREY << "ScavTrap default constructor called" << DEFAULT << std::endl; 
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << YELLOW << " * ScavTrap " << this->name << " is created. *" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &) : ClapTrap()
{
	std::cout << GREY << "copy constructor called" << DEFAULT << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << GREY << "copy assignment operator called" << DEFAULT << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREY << "ScavTrap destructor called" << DEFAULT << std::endl; 
}

std::string ScavTrap::getType() const
{
	return "ScavTrap";
}

/***** Functions *****/
void	ScavTrap::guardGate()
{
	if (this->hitPoints == 0)
		return ;
	if (this->energyPoints == 0)
	{
		std::cout << RED << "ScavTrap " << this->name << " has no energy!" << DEFAULT << std::endl;
		return ;
	}
	std::cout << BLUE << "ScavTrap " << this->name << " is in Gate keeper mode." << DEFAULT << std::endl;
}
