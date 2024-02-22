#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string myStr(argv[i]);
			for (unsigned int j = 0; j < myStr.length(); j++)
			{
				std::cout << char(toupper(myStr[j]));
			}
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	
	std::cout << "\n";
	return 0;
}