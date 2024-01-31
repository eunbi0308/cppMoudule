#ifndef ZOMBIE_H
# define ZOMBIE_H

# define YELLOW "\e[38;5;208m"
# define DEFAULT "\033[0m"

# include <iostream>
# include <string>
# include <cstdlib> // atoi()
# include <cstring> // for c_str

class Zombie
{
	private:
		std::string name;
	public:
		Zombie()
		{
		}
		~Zombie()
		{
			std::cout << this->name << " has been destroyed." << std::endl;
		}
		void	announceOfCreation();
		void	announce();
		void	giveName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif