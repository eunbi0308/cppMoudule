#include "Zombie.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int N = std::atoi(argv[1]);
		Zombie*	horde = zombieHorde(N, "Roy");
		delete [] horde;
	}
	else
		std::cout << "Please type number of Zombies you want to create." << std::endl;
	return 0;
}