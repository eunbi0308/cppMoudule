#include "Form.hpp"

Form::Form(std::string name, bool sign, unsigned int sGrade, unsigned int eGrade)
: name(name), sign(false), signGrade(sGrade), executeGrade(eGrade) {}

Form::Form(const Form &other)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
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
		this->sign = true;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "["<< this->getName() << "] An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}