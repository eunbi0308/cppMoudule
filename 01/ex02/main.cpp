#include <iostream>
#include <string>

int main()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "The memory address of the string	: " << &string << std::endl;
	std::cout << "The memory address held by the pointer	: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF	: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "The value of the string	: " << string << std::endl;
	std::cout << "The value of the string	: " << *stringPTR << std::endl;
	std::cout << "The value of the string	: " << stringREF << std::endl;

	return 0;
}