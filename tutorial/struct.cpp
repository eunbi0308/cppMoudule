#include <iostream>

struct {
	int			myNum;
	std::string	myString;

} myStructure;

int	main()
{
	myStructure.myNum = 1;
	myStructure.myString = "Hello World";

	std::cout << myStructure.myNum << "\n";
	std::cout << myStructure.myString << "\n";

	return (0);
}

/*****************************************************/

struct {
	int			year;
	std::string	model;
	std::string	brand;
} myCar1, myCar2;

int	main()
{
	myCar1.brand = "BMW";
	myCar1.model = "X5";
	myCar1.year = 1999;

	myCar2.brand = "Ford";
	myCar2.model = "Mustang";
	myCar2.year = 1969;

	std::cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
	std::cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";

	return (0);
}

/*****************************************************/
//Named Structures
struct car{
	int			year;
	std::string	model;
	std::string	brand;
};

int main()
{
	car myCar1;
	myCar1.brand = "BMW";
	myCar1.model = "X5";
	myCar1.year = 1999;

	car myCar2;
	myCar2.brand = "Ford";
	myCar2.model = "Mustang";
	myCar2.year = 1969;

	std::cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
	std::cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
}