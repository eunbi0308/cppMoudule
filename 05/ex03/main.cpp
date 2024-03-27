#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

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
		std::cout << RED << "Intern Test - SUCCESS" << DEFAULT << std::endl;

		Intern	intern;

		Bureaucrat	tom("Tom", 1);
		AForm		*shrubberyForm = intern.makeForm("Shrubbery creation", "Eindhoven");
		AForm		*robotomyForm = intern.makeForm("Robotomy request", "Roy");
		AForm		*pardonForm = intern.makeForm("Presidential pardon", "Martines");
		
		// Shrubbery
		std::cout << *shrubberyForm << std::endl;
		tom.signForm(*shrubberyForm);
		std::cout << *shrubberyForm  << std::endl;
		tom.executeForm(*shrubberyForm);
		std::cout << "\n";
		// Robotomy
		std::cout << *robotomyForm << std::endl;
		tom.signForm(*robotomyForm);
		std::cout << *robotomyForm  << std::endl;
		tom.executeForm(*robotomyForm);
		std::cout << "\n";
		// Pardon
		std::cout << *pardonForm << std::endl;
		tom.signForm(*pardonForm);
		std::cout << *pardonForm << std::endl;
		tom.executeForm(*pardonForm);
		std::cout << "\n";


		delete shrubberyForm;
		delete robotomyForm;
		delete pardonForm;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try
	{
		std::cout << std::endl;
		std::cout << RED << "Intern Test - FAILURE" << DEFAULT << std::endl;

		Intern	intern;

		AForm		*invalidForm = intern.makeForm("Invalid", "Invalid");

		std::cout << invalidForm << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}

	try 
	{
		std::cout << std::endl;
		std::cout << RED << "Copy Test" << DEFAULT << std::endl;

		Intern	intern;
		AForm		*shrubbery = intern.makeForm("Shrubbery creation", "Eindhoven");

		std::cout << GREY << "COPY CONSTRUCTOR" << DEFAULT << std::endl;
		AForm	*shrubbery2(shrubbery);
		std::cout << *shrubbery2 << std::endl;

		std::cout << std::endl;
		std::cout << GREY << "COPY OPERATOR ASSIGNMENT" << DEFAULT << std::endl;
		AForm		*robotomy = intern.makeForm("Robotomy request", "Roy");
		std::cout << *robotomy << std::endl;
		delete robotomy;
		robotomy = shrubbery;
		std::cout << *robotomy << std::endl;
	
		delete shrubbery;
		shrubbery = nullptr;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}