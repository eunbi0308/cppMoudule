#include "replace.hpp"



int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED << "Usage : <filename> <s1> <s2>" << DEFAULT << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (filename.empty())
	{
		std::cerr << RED << "Please type filename" << DEFAULT << std::endl;
		return (1);
	}
	if (s1.empty() || s2.empty())
	{
		std::cerr << RED << "Please type string" << DEFAULT << std::endl;
		return (1);
	}
	else if (s1 == s2)
	{
		std::cout << "The string you want to change is the same as the first string." << std::endl;
		return (1);
	}
	replaceFile(filename, s1, s2);
	return (0);
}