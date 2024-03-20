#include "PresidentialPardonForm.hpp"
#include <stdexcept> // runtime_error

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon Form", 25, 5), target("TARGET") 
{
	#ifdef DEBUG
		std::cout << GREY << "PresidentialPardonForm : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential Pardon Form", 25, 5), target(target)
{
	#ifdef DEBUG
		std::cout << GREY << "PresidentialPardonForm : constructor called" << DEFAULT << std::endl; 
	#endif

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), target(other.target)
{
	#ifdef DEBUG
		std::cout << GREY << "PresidentialPardonForm : Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	#ifdef DEBUG
		std::cout << GREY << "PresidentialPardonForm : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	if (this != &other)
	{
		AForm::operator=(other); // Call base class assignment operator.
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG
		std::cout << GREY << "PresidentialPardonForm : Destructor called" << DEFAULT << std::endl; 
	#endif
}

/*** Member function ***/
void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	AForm::execute(bureaucrat);
	if (this->getSignStatus() == false)
	{
		std::cout << YELLOW;
		throw std::runtime_error("Presiential Pardon Form has not been signed yet.");
	}
	std::cout << BLUE << this->target << " has been pardoned by Zaphod Beeblebrox." << DEFAULT << std::endl;
}