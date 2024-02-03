#include "replace.hpp"

std::string getNonEmptyInput(const std::string &prompt)
{
    std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);
	if (input.empty())
	{
		do
		{
			std::cout << GREY << "This field cannot be empty.\n" << DEFAULT;
			std::cout << prompt;
			std::getline(std::cin, input);
		} while (input.empty());
	}
    return input;
}

int	main()
{
	std::string filename, s1, s2;

	filename = getNonEmptyInput("Enter an input file name : ");
	s1 = getNonEmptyInput("Enter a string that you want to replace : ");
	s2 = getNonEmptyInput("Enter a replacement string : ");
	if (s1 == s2)
	{
		std::cout << "The string you want to change is the same as the first string." << std::endl;
		return (1);
	}
	replaceFile(filename, s1, s2);
	return (0);
}
