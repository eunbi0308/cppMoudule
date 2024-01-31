#include "Contact.hpp"

void	err(const char *msg)
{
	std::cerr << RED << msg << DEFAULT << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getNonEmptyInput(const std::string &prompt)
{
    std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);
	if (input.empty())
	{
		do
		{
			std::cout << GREY << "This field cannot be empty." << DEFAULT;
			std::cout << GREEN << prompt << DEFAULT << " >";
			std::getline(std::cin, input);
		} while (input.empty());
	}
    return input;
}

void	printShortenName(const std::string &str)
{
	if (str.length() > 10)
	{
		std::string	shortenedName = str.substr(0, 9) + '.';
		std::cout << std::setw(10) << std::setfill(' ') << shortenedName;
	}
	else
		std::cout << std::setw(10) << std::setfill(' ') << str;
}

bool containsOnlyDigits(const std::string &str)
{
	int	len = str.length();

    for (int i = 0; i < len; ++i) 
	{
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
