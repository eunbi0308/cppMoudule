#include "RobotomyRequestForm.hpp"
// #include <cstdlib>
#include <stdexcept> // runtime_error
#include <random>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy Request Form", 72, 45), target("TARGET") 
{
	#ifdef DEBUG
		std::cout << GREY << "RobotomyRequestForm : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy Request Form", 72, 45), target(target)
{
	#ifdef DEBUG
		std::cout << GREY << "RobotomyRequestForm : constructor called" << DEFAULT << std::endl; 
	#endif

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), target(other.target)
{
	#ifdef DEBUG
		std::cout << GREY << "RobotomyRequestForm : Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	#ifdef DEBUG
		std::cout << GREY << "RobotomyRequestForm : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	if (this != &other)
	{
		AForm::operator=(other); // Call base class assignment operator.
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG
		std::cout << GREY << "RobotomyRequestForm : Destructor called" << DEFAULT << std::endl; 
	#endif
}

/*** Member function ***/
void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	AForm::execute(bureaucrat);
	if (this->getSignStatus() == false)
	{
		std::cout << YELLOW;
		throw std::runtime_error("Robotomy Request Form has not been signed yet.");\
	}
	std::cout << BLUE << "🔧🦾🦿 Bzzz... Bzzz.." << DEFAULT << std::endl;
	// Generating 0 or 1 randomly.
	std::random_device	number; // Obtain a random number from hardware
	std::mt19937		gen(number()); // Seed the generator based one " Mersenne Twister algorithm"
	std::uniform_int_distribution<>distr(0,1); // Creates a uniform distribution of integers between 
	
	if (distr(gen) == 1)
		std::cout << BLUE << "🤖 " << this->target << " has been successfully robotomized." << std::endl;
	else
		std::cout << BLUE << "💥 The robotomy failed for " << this->target << "." << std::endl;
}