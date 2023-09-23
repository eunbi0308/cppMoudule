#include <iostream>

// Inheritance

/*
	Inheritance concpet

    derived class (child) - the class that inherits from another class
    base class (parent) - the class being inherited from

*/

// Base class
class	Vehicle {
	public:
		std::string	brand = "Ford";
		void	honk()
		{
			std::cout << "Tuut, tuut! \n";
		}
};

// Derived class
class Car: public Vehicle
{
	public:
		std::string model = "Mustang";
};

int	main()
{
	Car	myCar;
	myCar.honk();
	std::cout << myCar.brand + " " + myCar.model;
	return (0);
}


// Multilevel Inheritabce

//Base class (Parent)
class MyClass {
	public:
		void myFunction()
		{
			std::cout << "Some content in parent class.";
		}
};

//Derived class (child)
class MyChild: public MyClass {
};

//Derived class (grand child)
class MyGrandChild: public MyChild {
};

int	main()
{
	MyGrandChild	myObj;
	myObj.myFunction();
	return (0);
}


// Multiple Inheritance

//Base class
class MyClass {
  	public:
    	void myFunction() 
		{
      		std::cout << "Some content in parent class." ;
    	}
};

//Another base class
class MyOtherClass {
	public:
		void myOtherFunction()
		{
			std::cout << "Some content in another class.";
		}
};

//Derived class
class MyChildClass: public MyClass, public MyOtherClass {
};

int	main()
{
	MyChildClass myObj;
	myObj.myFunction();
	myObj.myOtherFunction();

	return 0;
}


// Access Specifiers
//protected

//Base class
class Employee {
	protected:
		int salary;
};

//Derived Class
class Programmer: public Employee {
	public:
		int bonus;
		void setSalary(int s)
		{
			salary = s;
		}
		int	getSalary()
		{
			return salary;
		}
};

int	main()
{
	Programmer	myObj;
	myObj.setSalary(50000);
	myObj.bonus = 15000;
	std::cout << "Salary: " << myObj.getSalary() << "\n";
	std::cout << "Bonus: " << myObj.bonus << "\n";
	return 0;
}
