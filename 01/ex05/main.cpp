#include "Harl.hpp"

int	main()
{
	Harl		harl;
	std::string	level;

	do
	{
		std::cout << "Enter a level : ";
		std::getline(std::cin, level);
		harl.complain(level);
		if (level == "EXIT")
			return 0;
	} while (true);

	return 0;
}