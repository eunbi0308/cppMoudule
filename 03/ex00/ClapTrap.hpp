#pragma once

#include <iostream>
#include <string>

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define BLUE "\033[38;5;38m"
# define DEFAULT "\033[0m"
# define PURPLE	"\033[38;2;200;160;255m"

class ClapTrap
{
	// Access Specifiers. "protected" is similar to private,
	// but it can also be accessed in the inherited class.
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		virtual std::string getType() const;
		std::string		getName(void);
		unsigned int	getDamage(void);
};