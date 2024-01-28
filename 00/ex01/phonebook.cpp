#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib> // atoi()
#include <cstring> // for c_str
#include <cctype> // isdigit()
#include "phonebook.hpp"

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
	public:
		Contact() {} //Default constructor
		Contact(std::string firstName, std::string lastName, std::string nickName, 
				std::string phoneNumber, std::string darkSecret)
		{
			this->firstName = firstName;
			this->lastName = lastName;
			this->nickName = nickName;
			this->phoneNumber = phoneNumber;
			this->darkSecret = darkSecret;
		}
		void	clearContact()
		{
			firstName.clear();
			lastName.clear();
			nickName.clear();
			phoneNumber.clear();
			darkSecret.clear();
		}
		std::string getFirstName();
		std::string getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkSecret();
};

class PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
	public:
		PhoneBook() : index(0) {} //Initialize index in the constructor
		void	printContactAllInfo(int index);
		void	add(Contact contact);
		void	search();
		void	printIndex(int index);
		void	printSummary();
		
		void	fillMaxContacts();
};

Contact	createContact(std::string firstName, std::string lastName, std::string nickName, 
				std::string phoneNumber, std::string darkSecret)
{
	return Contact(firstName, lastName, nickName, phoneNumber, darkSecret);
}

void	PhoneBook::fillMaxContacts()
{
	std::string firstName0 = "Roy", 
				lastName0 = "de Martines", 
				nickName0 = "Royboy", 
				phoneNumber0 = "0657678769", 
				darkSecret0 = "He's a babo";
	std::string firstName1 = "Eunbi", 
				lastName1 = "Cho", 
				nickName1 = "Zombie",
				phoneNumber1 = "0638602453",
				darkSecret1 = "She can bite.";
	std::string firstName2 = "Minie", 
				lastName2 = "de Martines", 
				nickName2 = "Dinosaurs", 
				phoneNumber2 = "123456789", 
				darkSecret2 = "She can bite hard.";
	std::string firstName3 = "Yejin", 
				lastName3 = "Park", 
				nickName3 = "Bagyejin", 
				phoneNumber3 = "01028089982", 
				darkSecret3 = "She is the youngest";
	std::string firstName4 = "Camila", 
				lastName4 = "Ignacia Prado", 
				nickName4 = "Kamille", 
				phoneNumber4 = "987654321", 
				darkSecret4 = "She has a daughter.";
	std::string firstName5 = "Violeta", 
				lastName5 = "Van Gennip Ignacia", 
				nickName5 = "Viole", 
				phoneNumber5 = "none", 
				darkSecret5 = "She doesn't have any tooth.";
	std::string firstName6 = "Bert", 
				lastName6 = "Van Gennip", 
				nickName6 = "Betty", 
				phoneNumber6 = "147258369", 
				darkSecret6 = "He's the father of Violeta";
	std::string firstName7 = "Hyebin", 
				lastName7 = "Park", 
				nickName7 = "Bagabin", 
				phoneNumber7 = "77777777", 
				darkSecret7 = "She's stubborn.";
	add(createContact(firstName0, lastName0, nickName0, phoneNumber0, darkSecret0));
	add(createContact(firstName1, lastName1, nickName1, phoneNumber1, darkSecret1));
	add(createContact(firstName2, lastName2, nickName2, phoneNumber2, darkSecret2));
	add(createContact(firstName3, lastName3, nickName3, phoneNumber3, darkSecret3));
	add(createContact(firstName4, lastName4, nickName4, phoneNumber4, darkSecret4));
	add(createContact(firstName5, lastName5, nickName5, phoneNumber5, darkSecret5));
	add(createContact(firstName6, lastName6, nickName6, phoneNumber6, darkSecret6));
	add(createContact(firstName7, lastName7, nickName7, phoneNumber7, darkSecret7));
}

std::string getNonEmptyInput(const std::string& prompt)
{
    std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);
	if (input.empty())
	{
		do
		{
			std::cout << "\033[0;90mThis field cannot be empty.\n\033[0m";
			std::cout << prompt;
			std::getline(std::cin, input);
		} while (input.empty());
	}
    return input;
}

Contact	createFromInput()
{
	std::string firstName, lastName, nickName, phoneNumber, darkSecret;
	
	firstName = getNonEmptyInput("\033[0;92mEnter first name : \n\033[0m >");
    lastName = getNonEmptyInput("\033[0;92mEnter last name : \n\033[0m >");
    nickName = getNonEmptyInput("\033[0;92mEnter nickname : \n\033[0m >");
    phoneNumber = getNonEmptyInput("\033[0;92mEnter phone number : \n\033[0m >");
    darkSecret = getNonEmptyInput("\033[0;92mEnter dark secret : \n\033[0m >");

    std::cout << "\e[38;5;208mA new contact is added. \n\n\033[0m";

	return Contact(firstName, lastName, nickName, phoneNumber, darkSecret);
}

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

void	err(const char *msg)
{
	std::cerr << msg << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

bool containsOnlyDigits(const std::string &str)
{

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (*it < '0' || *it > '9') {
            return false;
        }
    }
    return true;
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
		else if (std::atoi(index.c_str()) > this->index)
		{
			err("\033[1;91mThe contact doesn't exist.\n\033[0m");
			return ;
		}
		else
			printContactAllInfo(std::atoi(index.c_str()));
	}
	else
	{
		std::cout << "\e[38;5;208mThe phonebook is empty.\n\n \033[0m";
		return ;
	}
}

//Getter funcs
std::string	Contact::getFirstName()
{
	return this->firstName;
}

std::string	Contact::getLastName()
{
	return this->lastName;
}

std::string	Contact::getNickName()
{
	return this->nickName;
}

std::string	Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

std::string	Contact::getDarkSecret()
{
	return this->darkSecret;
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (true)
	{
		std::cout << "\033[0;92mPlease enter a command : (ADD, SEARCH or EXIT)\n\033[0m >";
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
			std::cout << "\033[1;91mInvalid command\n\033[0m"; 
	}
	return 0;
}