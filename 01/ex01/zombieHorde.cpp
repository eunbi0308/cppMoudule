#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].giveName(name);
		zombies[i].announceOfCreation();
		zombies[i].announce();
	}
	return (zombies);
}