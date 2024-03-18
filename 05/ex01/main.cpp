#include "Form.hpp"

int main()
{
	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Basic Test" << DEFAULT << std::endl;

		Bureaucrat	Tom("Tom", 1);
		Form		A("A", 50, 50);
		
		std::cout << Tom << std::endl;
		std::cout << A << std::endl;
	} 
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Limition Test" << DEFAULT << std::endl;

		Form	B("B", 50, 100);
		Form	C("C", -1800000, 50);

		std::cout << B << std::endl;
		std::cout << C << std::endl;

	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Sign Test" << DEFAULT << std::endl;

		Bureaucrat	Tom("Tom", 100);

		std::cout << Tom << std::endl;

		std::cout << GREY << "SUCCESS" << DEFAULT << std::endl;
		Form		A("A", 100, 1);

		std::cout << A << std::endl;
		Tom.signForm(A);
		std::cout << A << std::endl;

		std::cout << std::endl;
		std::cout << GREY << "Sign on a signed form" << DEFAULT << std::endl;
		Tom.signForm(A);

		std::cout << std::endl;
		std::cout << std::endl << GREY << "FAIL" << DEFAULT << std::endl;
		Form		B("B", 1, 1);

		std::cout << B << std::endl;
		Tom.signForm(B);
		std::cout << B << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Copy Test" << DEFAULT << std::endl;

		Form	A("A", 100, 100);

		std::cout << A << std::endl;

		std::cout << GREY << "COPY CONSTRUCTOR" << DEFAULT << std::endl;
		Form	B(A);

		std::cout << B << std::endl;

		std::cout << GREY << "COPY OPERATOR ASSIGNMENT" << DEFAULT << std::endl;
		Form	C("C", 1, 1);
		C = A;
		std::cout << C << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}