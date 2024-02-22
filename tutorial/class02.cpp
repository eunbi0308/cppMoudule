#include <iostream>

//Class Methods
// Inside

class MyClass {
	public:
		void myMethod()
		{
			std::cout << "Hello World!";
		}
};

int	main()
{
	MyClass myObj;
	myObj.myMethod();
	return 0;
}

// Outside
class Car {
	public:
		int	speed(int maxSpeed);
};

int	Car::speed(int maxSpeed)
{
	return (maxSpeed);
}

int	main()
{
	Car myObj;
	std::cout << myObj.speed(200);

	return (0);
}