#include <iostream>
#include <string>

class PhoneBook
{
	private:
		std::string contacts[8];
		static const size_t	MAX_CONTACTS = 8;
	public:
		// Setter
		void	setFirstName(std::string first);
		void	setLastName(std::string last);
		void	setNickName(std::string nick);
		void	setPhoneNumber(std::string num);
		void	setDarkSecret(std::string secret);
		// Getter
		void	getFirstName();
		void	getLastName();
		void	getNickName();
		void	getPhoneNumber();
		void	getDarkSecret();
};

class Contact
{
	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

//Setter funcs
void	setFirstName(std::string first)
{

}

void	setLastName(std::string last)
{

}

void	setNickName(std::string nick)
{

}

void	setPhoneNumber(std::string num)
{

}

void	setDarkSecret(std::string secret)
{

}

//Getter funcs
void	getFirstName(std::string first)
{

}

void	getLastName(std::string last)
{

}

void	getNickName(std::string nick)
{

}

void	getPhoneNumber(std::string num)
{

}

void	getDarkSecret(std::string secret)
{

}

int	main(int argc, char **argv)
{
	PhoneBook	phoneBook;
	Contact		contact;

}