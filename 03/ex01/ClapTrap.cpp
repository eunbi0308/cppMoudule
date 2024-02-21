#include "ClapTrap.hpp"
#include <iostream>
#include <cxxabi.h>
#include <typeinfo>

ClapTrap::ClapTrap()
{
	std::cout << GREY << "ClapTrap constructor called" << DEFAULT << std::endl; 
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << YELLOW << " * ClapTrap " << this->name << " is created. *" << DEFAULT << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &)
{
	std::cout << GREY << "copy constructor called" << DEFAULT << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << GREY << "copy assignment operator called" << DEFAULT << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << GREY << "ClapTrap Destructor called" << DEFAULT << std::endl; 
}

/*** Functions ***/
void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
		return;
	if (this->energyPoints <= 0)
	{
		std::cout << RED << getType() << " " << this->name << " has no energy!" << DEFAULT << std::endl;
		return ;
	}
	std::cout <<  getType() << " " << this->name <<  " attacks " << target <<
				", causing [" << attackDamage << "] points of damage!" << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << getType() << " " << this->name << " takes [" << amount << "] points of damage. :(" << std::endl;
	if (this->hitPoints == 0)
		return;
	if (hitPoints <= amount)
	{
		std::cout << RED << getType() << " " << this->name << " died. ☠" << DEFAULT << std::endl;
		if (amount > this->hitPoints)
			this->hitPoints = 0;
		else
			this->hitPoints -= amount;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "- Now " << this->name << " has total [" << hitPoints << "] hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
		return ;
	if (this->energyPoints <= 0)
	{
		std::cout << RED << getType() << " "  << this->name << " has no energy!" << DEFAULT << std::endl;
		return ;
	}
	std::cout << GREEN << getType() << " "  << this->name << " repaired [" << amount << "] hit points." << DEFAULT << std::endl;
	this->hitPoints += amount;
	std::cout << GREEN << "- Now " << this->name << " has total [" << hitPoints << "] hit points." << DEFAULT << std::endl;
	this->energyPoints--;
}

std::string ClapTrap::getType() const
{
	return "ClapTrap";
}

std::string	ClapTrap::getName(void)
{
	return this->name;
}

unsigned int ClapTrap::getDamage(void)
{
	return this->attackDamage;
}