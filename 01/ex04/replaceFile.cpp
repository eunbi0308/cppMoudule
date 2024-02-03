#include "replace.hpp"

std::string	replaceStr(std::string line, std::string str, size_t start, size_t end)
{
		std::string	replacedLine = line.substr(0, start);
		replacedLine.append(str);
		replacedLine.append(line.substr(end, line.length()));

		return replacedLine;
}

void	replaceFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
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
		size_t	start = 0;
		size_t	end = s1.length();
		while (line.find(s1, start) != std::string::npos)
		{
			line = replaceStr(line, s2, start, end);
		}
		outFile << line << std::endl;
	}
	// Close files
	inFile.close();
	outFile.close();
}