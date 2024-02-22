#ifndef ZOMBIE_H
# define ZOMBIE_H

# define YELLOW "\e[38;5;208m"
# define DEFAULT "\033[0m"

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void announce();
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif