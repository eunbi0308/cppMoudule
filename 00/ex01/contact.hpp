#ifndef CONTACT_H
# define CONTACT_H

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

#endif