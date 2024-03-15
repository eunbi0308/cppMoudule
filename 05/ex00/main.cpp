#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Basic Test" << DEFAULT << std::endl;

		Bureaucrat Tom("Tom", 1);
		Bureaucrat Andy("Andy", 75);
		Bureaucrat Jerry("Jerry", 150);

		std::cout << Tom << std::endl;
		std::cout << Andy << std::endl;
		std::cout << Jerry << std::endl;
	} 
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Increment Test" << DEFAULT << std::endl;

		Bureaucrat Tom("Tom", 1);
		Bureaucrat Andy("Andy", 75);
		Bureaucrat Jerry("Jerry", 150);

		std::cout << GREY << "BEFORE" << DEFAULT << std::endl;
		std::cout << Tom << std::endl;
		std::cout << Andy << std::endl;
		std::cout << Jerry << std::endl;

		std::cout << GREY << "INCREMENTING" << DEFAULT << std::endl;
		Tom.incrementGrade();
			std::cout << Tom << std::endl;
		Andy.incrementGrade();
			std::cout << Andy << std::endl;
		Jerry.incrementGrade();
					std::cout << Jerry << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Decrement Test" << DEFAULT << std::endl;

		Bureaucrat Tom("Tom", 1);
		Bureaucrat Andy("Andy", 75);
		Bureaucrat Jerry("Jerry", 150);

		std::cout << GREY << "BEFORE" << DEFAULT << std::endl;
		std::cout << Tom << std::endl;
		std::cout << Andy << std::endl;
		std::cout << Jerry << std::endl;

		std::cout << GREY << "DECREMENTING" << DEFAULT << std::endl;
		Tom.decrementGrade();
			std::cout << Tom << std::endl;
		Andy.decrementGrade();
			std::cout << Andy << std::endl;
		Jerry.decrementGrade();
			std::cout << Jerry << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Error Test" << DEFAULT << std::endl;

		Bureaucrat Tom("Tom", 0);
		Bureaucrat Andy("Andy", -10);
		Bureaucrat Jerry("Jerry", 1800000);

		std::cout << Tom << std::endl;
		std::cout << Andy << std::endl;
		std::cout << Jerry << std::endl;

	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Copy Test" << DEFAULT << std::endl;

		Bureaucrat Tom;
		// Bureaucrat Andy("Andy", 75);
		Bureaucrat Jerry("Jerry", 1);

		std::cout << Tom << std::endl;
		std::cout << Jerry << std::endl;

		std::cout << GREY << "COPY CONSTRUCTOR" << DEFAULT << std::endl;
		Bureaucrat Andy(Jerry);
		std::cout << Andy << std::endl;

		std::cout << GREY << "COPY OPERATOR ASSIGNMENT" << DEFAULT << std::endl;
		Andy = Tom;
		std::cout << Andy << std::endl;

	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}