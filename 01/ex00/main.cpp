#include "Zombie.hpp"

int main()
{
	//Create a heap Zombie
	Zombie	*heap = newZombie("Heap");
	heap->announce();
	//Create a stack Zombie
	randomChump("Stack");
	//Delete the heap Zombie
	delete heap;

	return 0;
}