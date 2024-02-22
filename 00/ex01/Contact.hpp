#ifndef CONTACT_H
# define CONTACT_H

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define DEFAULT "\033[0m"

# include <iostream>
# include <string>
# include <limits>
# include <iomanip> //setw() and setfill()

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
		std::string phoneNumber, std::string darkSecret);
		std::string getFirstName();
		std::string getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkSecret();
};

Contact	createContact(std::string firstName, std::string lastName, std::string nickName, 
				std::string phoneNumber, std::string darkSecret);
#endif