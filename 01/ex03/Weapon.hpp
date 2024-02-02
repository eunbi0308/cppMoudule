#ifndef WEAPON_H
# define  WEAPON_H

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define DEFAULT "\033[0m"

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
	
		std::string	getType();
		void		setType(std::string type);
};

#endif