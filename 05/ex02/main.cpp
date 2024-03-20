#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Basic Test" << DEFAULT << std::endl;

		Bureaucrat				tom("Tom", 1);
	
		ShrubberyCreationForm	shrubberyForm("Eindhoven");
		RobotomyRequestForm		robotomyForm("Roy");
		PresidentialPardonForm	pardonForm("Martines");
			
		std::cout << tom << std::endl << std::endl;
		std::cout << shrubberyForm << std::endl << std::endl;
		std::cout << robotomyForm << std::endl << std::endl;
		std::cout << pardonForm << std::endl << std::endl;

		std::cout << GREY << "DEFAULT" << DEFAULT << std::endl;
		ShrubberyCreationForm	defaultShrubberyForm;
		RobotomyRequestForm		defaultRobotomyForm;
		PresidentialPardonForm	defaultPardonForm;
		std::cout << defaultShrubberyForm << std::endl << std::endl;
		std::cout << defaultRobotomyForm << std::endl << std::endl;
		std::cout << defaultPardonForm << std::endl << std::endl;
	} 
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Sign and Excute Test - SUCCESS" << DEFAULT << std::endl;

		Bureaucrat				tom("Tom", 1);
		ShrubberyCreationForm	shrubberyForm("Eindhoven");
		RobotomyRequestForm		robotomyForm("Roy");
		PresidentialPardonForm	pardonForm("Martines");

		// Shrubbery
		std::cout << shrubberyForm << std::endl;
		tom.signForm(shrubberyForm);
		std::cout << shrubberyForm  << std::endl;
		tom.executeForm(shrubberyForm);
		std::cout << "\n";
		// Robotomy
		std::cout << robotomyForm << std::endl;
		tom.signForm(robotomyForm);
		std::cout << robotomyForm  << std::endl;
		tom.executeForm(robotomyForm);
		std::cout << "\n";
		// Pardon
		std::cout << pardonForm << std::endl;
		tom.signForm(pardonForm);
		std::cout << pardonForm << std::endl;
		tom.executeForm(pardonForm);
		std::cout << "\n";

	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Sign and Excute Test - FAILURE" << DEFAULT << std::endl;

		Bureaucrat				tom("Tom", 138);
		ShrubberyCreationForm	shrubberyForm("Eindhoven");
		RobotomyRequestForm		robotomyForm("Roy");
		PresidentialPardonForm	pardonForm("Martines");

		std::cout << GREY << "***** Not executable *****" << DEFAULT << std::endl;
		// Shrubbery
		std::cout << shrubberyForm << std::endl;
		tom.signForm(shrubberyForm);
		std::cout << shrubberyForm  << std::endl;
		tom.executeForm(shrubberyForm);
		std::cout << "\n";
		// Robotomy
		std::cout << robotomyForm << std::endl;
		tom.signForm(robotomyForm);
		std::cout << robotomyForm  << std::endl;
		tom.executeForm(robotomyForm);
		std::cout << "\n";
		// Pardon
		std::cout << pardonForm << std::endl;
		tom.signForm(pardonForm);
		std::cout << pardonForm << std::endl;
		tom.executeForm(pardonForm);
		std::cout << "\n";

		std::cout << GREY << "***** Executable but not signed *****" << DEFAULT << std::endl;
		Bureaucrat				jerry("Jerry", 1);

		// Robotomy
		std::cout << robotomyForm  << std::endl;
		jerry.executeForm(robotomyForm);
		std::cout << "\n";
		// Pardon
		std::cout << pardonForm << std::endl;
		jerry.executeForm(pardonForm);
		std::cout << "\n";

	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Copy Test" << DEFAULT << std::endl;

		Bureaucrat				tom("Tom", 1);
		Bureaucrat				jerry("Jerry", 150);

		std::cout << GREY << "COPY CONSTRUCTOR" << DEFAULT << std::endl;
		Bureaucrat andy(tom);
		std::cout << andy << std::endl;

		std::cout << GREY << "COPY OPERATOR ASSIGNMENT" << DEFAULT << std::endl;
		jerry = tom;
		std::cout << jerry << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}