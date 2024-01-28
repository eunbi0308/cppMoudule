#include "phonebook.hpp"

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

Contact	createContact(std::string firstName, std::string lastName, std::string nickName, 
				std::string phoneNumber, std::string darkSecret)
{
	return Contact(firstName, lastName, nickName, phoneNumber, darkSecret);
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