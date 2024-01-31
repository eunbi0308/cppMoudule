#include <cstdlib> // atoi()
#include <cstring> // for c_str
#include "PhoneBook.hpp"

void	PhoneBook::add(Contact contact)
{
	if (index < 8)
		this->contacts[index] = contact;
	else
	{
		int	oldestIndex = index % 8;
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
		std::cout << GREEN << "Enter an index of a contact" << DEFAULT << " >";
		std::cin >> index;
		if (std::atoi(index.c_str()) < 0 || std::atoi(index.c_str()) >= 8)
		{
			err("Typed index is out of bound.\n");
			return ;
		}
		else if (containsOnlyDigits(index) == false)
		{
			err("Invalid input. Enter a number.\n");
			return ;
		}
		else if (std::atoi(index.c_str()) >= this->index)
		{
			err("The contact doesn't exist.\n");
			return ;
		}
		else
			printContactAllInfo(std::atoi(index.c_str()));
	}
	else
	{
		std::cout << YELLOW << "The phonebook is empty.\n\n" << DEFAULT;
		return ;
	}
}


int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (true)
	{
		std::cout << GREEN << "Please enter a command : (ADD, SEARCH or EXIT)\n\033[0m >";
		std::getline(std::cin, cmd);
		if (cmd == "TEST")
			phoneBook.fillMaxContacts();
		else if (cmd == "ADD")
			phoneBook.add(createFromInput());
		else if (cmd == "SEARCH")
			phoneBook.search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid command\n" << DEFAULT; 
	}
	return 0;
}