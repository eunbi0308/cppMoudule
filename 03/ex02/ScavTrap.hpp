#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &);
		ScavTrap& operator=(const ScavTrap &other);
		~ScavTrap();

		std::string getType() const;
		void	guardGate();
};