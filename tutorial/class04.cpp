#include <iostream>

// Access Specifiers

/*
    public - members are accessible from outside the class
    private - members cannot be accessed (or viewed) from outside the class
    protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.

	By default, all members of a class are private if you don't specify an access specifier:
*/


class MyClass {
  public:    // Public access specifier
    int x;   // Public attribute
  private:   // Private access specifier
    int y;   // Private attribute
};

int main() 
{
  MyClass myObj;
  myObj.x = 25;  // Allowed (public)
  myObj.y = 50;  // Not allowed (private)

  return 0;
}

// Encapsulation is to make sure that "sensitive" data is hidden from users. To achieve this, you must declare class variables/attributes as private

// Access Private Members

class Employee {
	private:
		int	salary;
	public:
		//Setter
		void setSalary(int s)
		{
			salary = s;
		}
		int	getSalary()
		{
			return	salary;
		}
};

int	main()
{
	Employee	myObj;
	myObj.setSalary(50000);
	std::cout << myObj.getSalary();

	return (0);
}
