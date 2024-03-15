#include "Form.hpp"

Form::Form() : name("DEFAULT FORM"), sign(false), signGrade(1), executeGrade(1) 
{
	#ifdef DEBUG
		std::cout << GREY << "Form : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Form::Form(std::string name, bool sign, unsigned int sGrade, unsigned int eGrade)
: name(name), sign(false), signGrade(sGrade), executeGrade(eGrade) 
{
	#ifdef DEBUG
		std::cout << GREY << "Form : constructor called" << DEFAULT << std::endl; 
	#endif
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException(this->name.c_str(), "The grade is too high. The grade range is 1 - 150.");
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException(this->name.c_str(), "The grade is too low. The grade range is 1 - 150.");
}

Form::Form(const Form &other)
: name(other.getName()), sign(false), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade())
{
	#ifdef DEBUG
		std::cout << GREY << "Form : Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

Form &Form::operator=(const Form &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Form : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif

	this->sign = other.sign;
	return *this;
}

Form::~Form()
{
	#ifdef DEBUG
		std::cout << GREY << "Form : Destructor called" << DEFAULT << std::endl; 
	#endif
}

std::string		Form::getName() const
{
	return this->name;
}

unsigned int	Form::getSignGrade() const
{
	return this->signGrade;
}

unsigned int	Form::getExecuteGrade() const
{
	return this->executeGrade;
}

void			Form::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->getSignGrade())
			throw GradeTooLowException(bureaucrat.getName());
		std::cout << PURPLE << bureaucrat.getName() << " signed " << this->getName() << "✒️" << DEFAULT << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "["<< this->getName() << "] An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}