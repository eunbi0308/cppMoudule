#include "PhoneBook.hpp"

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

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, 
		std::string phoneNumber, std::string darkSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkSecret = darkSecret;
}

Contact	createContact(std::string firstName, std::string lastName, std::string nickName, 
				std::string phoneNumber, std::string darkSecret)
{
	return Contact(firstName, lastName, nickName, phoneNumber, darkSecret);
}

Contact	createFromInput()
{
	std::string firstName, lastName, nickName, phoneNumber, darkSecret;
	
	firstName = getNonEmptyInput("Enter first name : \n");
    lastName = getNonEmptyInput("Enter last name : \n");
    nickName = getNonEmptyInput("Enter nickname : \n");
    phoneNumber = getNonEmptyInput("Enter phone number : \n");
    darkSecret = getNonEmptyInput("Enter dark secret : \n");

    std::cout << YELLOW << "A new contact is added. \n\n" << DEFAULT;

	return Contact(firstName, lastName, nickName, phoneNumber, darkSecret);
}