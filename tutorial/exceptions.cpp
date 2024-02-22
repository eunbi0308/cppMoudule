#include <iostream>

// Try and Catch (as a pair)
try {
	//Bloxk of code to try
	throw excpetion;
}
catch () {
	//Block of code to handle errors
}

int main()
{
	try {
		int	age = 15;
		if (age >= 18) {
			std::cout << "Access granted - you are old enough.";
		} else {
			throw (age);
		}
	}
	catch (int myNum) {
		std::cout << "Access denied - You must be at least 18 years old.\n";
		std::cout << "Age is: " << myNum;
	}
}

int main()
{
	try {
		int	age = 15;
		if (age >= 18) {
			std::cout << "Access granted - you are old enough.";
		} else {
			throw 505;
		}
	}
	catch (int myNum) {
		std::cout << "Access denied - You must be at least 18 years old.\n";
		std::cout << "Error number: " << myNum;
	}
}

int main()
{
	try {
		int	age = 15;
		if (age >= 18) {
			std::cout << "Access granted - you are old enough.";
		} else {
			throw 505;
		}
	}
	catch (...) {
		std::cout << "Access denied - You must be at least 18 years old.\n";
	}
}