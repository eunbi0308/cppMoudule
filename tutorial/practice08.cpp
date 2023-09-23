#include <iostream>

int main ()
{
	//Array
	std::string cars[4] = {"Volvo", "BMW", "Ford", "Kia"};
	std::cout << cars[0] << "\n";

	//Get the size of an array in bytes
	int myNumbers[5] = {10, 20, 30, 40, 50};
	std::cout << sizeof(myNumbers);

	//To find out how many elements an array has
	int getArrayLength = sizeof(myNumbers) / sizeof(int);
	std::cout << getArrayLength;

	//more sustainable way
	for (int i = 0; i < sizeof(myNumbers) / sizeof(int); i++)
	{
		std::cout << myNumbers[i] << "\n";
	}
	return (0);
}