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
		Zombie(std::string name)
		{
			this->name = name;
			std::cout << this->name << " has been created." << std::endl;
		}
		~Zombie()
		{
			std::cout << this->name << " has been destroyed." << std::endl;
		}
		void announce();
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif