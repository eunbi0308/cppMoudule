#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base	*generate(void)
{
	std::random_device	number; // Obtain a random number from hardware
	std::mt19937		gen(number()); // Seed the generator based one " Mersenne Twister algorithm"
	std::uniform_int_distribution<>distr(0,2); // Creates a uniform distribution of integers between 

	switch (distr(gen))
	{
		case 0:
				return new A;
		case 1:
				return new B;
		case 2:
				return new C; 
	}
	return nullptr;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void	identify(Base* p)
{
	if (!p)
	{
		std::cerr << "Null pointer encountered" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer C" << std::endl;
	else
		std::cerr << "Unknown type" << std::endl;
}
// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// But without using pointer inside of the function.
// In reference case, cannot return NULL when dynamic cast fails. So exception occurs.
void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference A" << std::endl;
		static_cast<void>(a);
	}
	catch(const std::exception& e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Reference B" << std::endl;
		static_cast<void>(b);
	}
	catch(const std::exception& e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Reference C" << std::endl;
		static_cast<void>(c);
	}
	catch(const std::exception& e) {}
}
