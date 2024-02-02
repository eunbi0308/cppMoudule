#include "PhoneBook.hpp"

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