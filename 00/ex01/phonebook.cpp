#include <cstdlib> // atoi()
#include <cstring> // for c_str
#include "phonebook.hpp"

void	PhoneBook::add(Contact contact)
{
	if (index < 8)
		this->contacts[index] = contact;
	else
	{
		int	oldestIndex = index % 8;
		contacts[oldestIndex].clearContact();
		contacts[oldestIndex] = contact;
	}
	this->index++;
}

void	PhoneBook::printSummary()
{
	int	i = 0;

	std::cout << std::endl; 
	while (i < this->index && i < 8)
	{
		std::cout << std::setw(10) << std::setfill(' ') << i;
		std::cout << '|';
		printShortenName(contacts[i].getFirstName());
		std::cout << '|';
		printShortenName(contacts[i].getLastName());
		std::cout << '|';
		printShortenName(contacts[i].getNickName());
		std::cout << std::endl;
		i++;
	}
}

void	PhoneBook::printContactAllInfo(int index)
{
	std::cout << std::endl;
	std::cout << "- First name		: " << contacts[index].getFirstName() << std::endl;
	std::cout << "- Last name		: " << contacts[index].getLastName() << std::endl;
	std::cout << "- Nickname		: " << contacts[index].getNickName() << std::endl;
	std::cout << "- Phone number		: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "- Darkest secret	: " << contacts[index].getDarkSecret() << std::endl;
	std::cout << std::endl;
	 // Clear input buffer
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	PhoneBook::search()
{
	std::string	index;

	if (this->index >= 1)
	{
		printSummary();
		std::cout << "\033[0;92mEnter an index of a contact\n\033[0m >";
		std::cin >> index;
		if (std::atoi(index.c_str()) < 0 || std::atoi(index.c_str()) >= 8)
		{
			err("\033[1;91mTyped index is out of bound.\n\033[0m");
			return ;
		}
		else if (containsOnlyDigits(index) == false)
		{
			err("\033[1;91mInvalid input. Enter a number.\n\033[0m");
			return ;
		}
		else if (std::atoi(index.c_str()) >= this->index)
		{
			err("\033[1;91mThe contact doesn't exist.\n\033[0m");
			return ;
		}
		else
			printContactAllInfo(std::atoi(index.c_str()));
	}
	else
	{
		std::cout << "\e[38;5;208mThe phonebook is empty.\n\n\033[0m";
		return ;
	}
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (true)
	{
		std::cout << "\033[0;92mPlease enter a command : (ADD, SEARCH or EXIT)\n\033[0m >";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phoneBook.add(createFromInput());
		else if (cmd == "SEARCH")
			phoneBook.search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "\033[1;91mInvalid command\n\033[0m"; 
	}
	return 0;
}