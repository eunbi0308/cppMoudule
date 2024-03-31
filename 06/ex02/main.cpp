#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base*	obj = generate();

	std::cout << RED << "Test - pointer" << DEFAULT << std::endl;
	identify(obj);

	std::cout << std::endl;
	std::cout << RED << "Test - reference" << DEFAULT << std::endl;
	identify(*obj);

	delete obj;
}