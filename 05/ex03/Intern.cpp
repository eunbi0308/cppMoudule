#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	#ifdef DEBUG
		std::cout << GREY << "Intern : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Intern::Intern(const Intern &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Intern : Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Intern : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	if (this == &other)
		(void)other;
	return *this;
}

Intern::~Intern()
{
	#ifdef DEBUG
		std::cout << GREY << "Intern : Destructor called" << DEFAULT << std::endl; 
	#endif
}

AForm*	Intern::makeForm(std::string str, std::string target)
{
	std::string	forms[3] = {"Shrubbery creation", "Robotomy request", "Presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == str)
		{
			std::cout << PINK << "Intern creates " << str << " form." << DEFAULT << std::endl;
			switch (i)
			{
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw Intern::InvalidFormException(str);
}

const char* Intern::InvalidFormException::what() const throw()
{
	std::cerr << "[" << form << "]";
	return (" is an invliad form.\nAvailable forms : 'Shrubbery creation', 'Robotomy request' and 'Presidential pardon'.");
}