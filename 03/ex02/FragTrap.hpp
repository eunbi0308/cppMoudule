#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &);
		FragTrap& operator=(const FragTrap &other);
		~FragTrap();
	
		std::string getType() const;
		void	highFivesGuys(void);
};