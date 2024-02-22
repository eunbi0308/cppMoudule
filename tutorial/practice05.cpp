#include <iostream>

int main()
{
	int myAge = 25;
	int votingAge = 18;

	if (myAge >= votingAge)
		std::cout << "Old enough to vote!\n";
	else
		std::cout << "Not old enough to vote.\n";
	return (0);
}