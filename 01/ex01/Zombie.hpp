#ifndef ZOMBIE_H
# define ZOMBIE_H

# define YELLOW "\e[38;5;208m"
# define DEFAULT "\033[0m"

# include <iostream>
# include <string>
# include <cstdlib> // atoi()

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void	announce();
		void	giveName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif