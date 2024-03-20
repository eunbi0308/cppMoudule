#include "ShrubberyCreationForm.hpp"
#include <stdexcept> // runtime_error
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery Creation Form", 145, 137), target("TARGET") 
{
	#ifdef DEBUG
		std::cout << GREY << "ShrubberyCreationForm : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	#ifdef DEBUG
		std::cout << GREY << "ShrubberyCreationForm : constructor called" << DEFAULT << std::endl; 
	#endif

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), target(other.target)
{
	#ifdef DEBUG
		std::cout << GREY << "ShrubberyCreationForm : Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	#ifdef DEBUG
		std::cout << GREY << "ShrubberyCreationForm : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	if (this != &other)
	{
		AForm::operator=(other); // Call base class assignment operator.
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG
		std::cout << GREY << "ShrubberyCreationForm : Destructor called" << DEFAULT << std::endl; 
	#endif
}

/*** Member function ***/
void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	AForm::execute(bureaucrat);
	if (this->getSignStatus() == false)
	{
		std::cout << YELLOW;
		throw std::runtime_error("Shrubbery Creation Form has not been signed yet.");
	}
	std::ofstream	file;
	std::string		outfile = this->target + "_shrubbery";
	file.open(outfile);
	if (!file)
	{
		std::cerr << "Failed to open the output file." << std::endl;
		return ;
	}
	file << ASCII_TREE;
	file.close();
}