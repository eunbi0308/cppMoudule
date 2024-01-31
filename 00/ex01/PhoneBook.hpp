#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

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
		void	printSummary();

		void	fillMaxContacts();
};

/*** utils.cpp ***/
Contact		createFromInput();
void		err(const char *msg);
std::string	getNonEmptyInput(const std::string &prompt);
void		printShortenName(const std::string &str);
bool 		containsOnlyDigits(const std::string &str);
#endif