#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << GREY << "FragTrap default constructor called" << DEFAULT << std::endl; 
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << YELLOW << " * FragTrap " << this->name << " is created. *" << DEFAULT << std::endl;
}

FragTrap::FragTrap(const FragTrap &) : ClapTrap()
{
	std::cout << GREY << "copy constructor called" << DEFAULT << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << GREY << "copy assignment operator called" << DEFAULT << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << GREY << "FragTrap destructor called" << DEFAULT << std::endl; 
}

std::string FragTrap::getType() const
{
	return "FragTrap";
}

/*** Functions ***/
void	FragTrap::highFivesGuys(void)
{
	if (this->hitPoints == 0)
		return ;
	if (this->energyPoints == 0)
	{
		std::cout << RED << "FragTrap " << this->name << " has no energy!" << DEFAULT << std::endl;
		return ;
	}
	std::cout << PURPLE << "FragTrap " << this->name << " gives a high five! 🙌" << DEFAULT << std::endl;
}