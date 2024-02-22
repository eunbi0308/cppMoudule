#include "Zombie.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int N = std::stoi(argv[1]);
		if (N <= 0)
		{
			std::cout << "Invalid number. Please enter a number above 0." << std::endl;
			return EXIT_FAILURE;
		}
		Zombie*	horde = zombieHorde(N, "Roy");
		delete [] horde;
	}
	else
		std::cout << "Please type number of Zombies you want to create." << std::endl;
	return 0;
}