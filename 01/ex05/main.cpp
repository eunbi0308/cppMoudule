#include "Harl.hpp"

int	main()
{
	Harl		harl;
	std::string	level;

	do
	{
		std::cout << "Enter a level : ";
		std::getline(std::cin, level);
		if (level == "EXIT")
			return 0;
		harl.complain(level);
	} while (true);

	return 0;
}