#include "Bureaucrat.hpp"

int main()
{
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
		Andy.incrementGrade();
		Jerry.incrementGrade();

		std::cout << GREY << "AFTER" << DEFAULT << std::endl;
		std::cout << Tom << std::endl;
		std::cout << Andy << std::endl;
		std::cout << Jerry << std::endl;

	}
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
		Andy.decrementGrade();
		Jerry.decrementGrade();

		std::cout << GREY << "AFTER" << DEFAULT << std::endl;
		std::cout << Tom << std::endl;
		std::cout << Andy << std::endl;
		std::cout << Jerry << std::endl;
	}
}