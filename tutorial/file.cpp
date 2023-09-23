#include <iostream>
#include <fstream> // create, write and read

//Create and Write To a File
int	main()
{
	std::ofstream MyFile("filename.txt");
	MyFile << "Files can be tricky, but it is fun enough!";
	MyFile.close();
}

//Read a File

int	main()
{
	std::string	myText;

	std::ifstream MyReadFile("filename.txt");
	while (getline (MyReadFile, myText))
	{
		std::cout << myText;
	}
	MyReadFile.close();
}