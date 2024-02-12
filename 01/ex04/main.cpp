#include "replace.hpp"

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << RED << "USAGE : ./ex04 <filename> <s1> <s2>" << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	replaceFile(filename, s1, s2);

	return 0;
}