#include <iostream>

// Constructors is a special method 
// that is automatically called when an object of a class is created.

class MyClass {
	public:
		MyClass() {
			std::cout << "Hello World!";
		}
};

int	main()
{
	MyClass myObj;

	return (0);
}

//Constructor Parameters
class Car {
	public:
		std::string brand;
		std::string model;
		int	year;
		Car(std::string x, std::string y, int z)
		{
			brand = x;
			model = y;
			year = z;
		}
};

int main()
{
	Car carObj1("BMW", "X5", 1999);
	Car carObj2("Ford", "Mustang", 1969);

	std::cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
	std::cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
	
	return 0;
}

// Defining constructor outside the class.
class Car {
	public:
		std::string brand;
		std::string model;
		int	year;
		Car(std::string x, std::string y, int z);
};

Car::Car(std::string x, std::string y, int z)
{
	brand = x;
	model = y;
	year = z;
};

int main()
{
	Car carObj1("BMW", "X5", 1999);
	Car carObj2("Ford", "Mustang", 1969);

	std::cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
	std::cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
	
	return 0;
}