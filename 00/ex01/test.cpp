#include "PhoneBook.hpp"
#include "Contact.hpp"

// void	fillMaxContacts();

		// if (cmd == "TEST")
		// 	phoneBook.fillMaxContacts();

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