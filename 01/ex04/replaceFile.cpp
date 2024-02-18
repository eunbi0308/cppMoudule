#include "replace.hpp"

bool	inputChecker(const std::string filename, const std::string s1, const std::string s2)
{
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << RED << "Invalid input. input cannot be empty." << DEFAULT << std::endl;
		return (false);
	}
	if (s1 == s2)
	{
		std::cout << RED << "The string you want to change is the same as the first string." << DEFAULT << std::endl;
		return (false);
	}
	return (true);
}

void	replaceFile(const std::string filename, const std::string s1, const std::string s2)
{
	if (inputChecker(filename, s1, s2) == false)
		return ;
	// Open the input file
	std::ifstream	inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "Error opening file : " << filename << std::endl;
		return ;
	}
	// Create an out file (input filename.replace)
	std::ofstream	outFile(filename + ".replace");
	if (!outFile.is_open())
	{
		std::cerr << "Error creating file : " << filename + ".replace" << std::endl;
		return ;
	}
	// Read the input file line by line
	std::string line;
	while (std::getline(inFile, line))
	{
		int 	searchPosition = 0;
		size_t	start;
		while ((start = line.find(s1, searchPosition)) != std::string::npos)
		{
			// To replace only once.
			line.erase(start, s1.length());
			line.insert(start, s2);
			searchPosition = start + s2.length();
		}
		outFile << line << std::endl;
	}
	// Close files
	inFile.close();
	outFile.close();
}