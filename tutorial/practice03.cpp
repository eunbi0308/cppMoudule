#include <iostream>
#include <string>

int	main()
{
	//string join
	std::string s1 = "Hello ";
	std::string s2 = "World.";
	std::cout << s1 + s2 << "\n";

	//string concatenate with append()
	std::cout << s1.append(s2) << "\n"; 

	//length()
	std::string str = "ABCDEFGHIJKOREA";
	std::cout << "The length of the str is: " << str.length() << "\n";
	//size()
	std::cout << "The length of the str is: " << str.size() << "\n";

	str[0] = 'Z';
	std::cout << str << "\n";

	//getline()
	std::string fullName;
	std::cout << "Type your full name: ";
	getline(std::cin, fullName);
	std::cout << "Your name is: " << fullName << "\n";
	return (0);
}