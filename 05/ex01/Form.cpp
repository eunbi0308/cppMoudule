#include "Form.hpp"

Form::Form(std::string name, bool sign, unsigned int sGrade, unsigned int eGrade)
: name(name), sign(false), signGrade(sGrade), executeGrade(eGrade) {}

std::string		Form::getName() const
{

}

unsigned int	Form::getSignGrade() const
{

}

unsigned int	Form::getExecuteGrade() const
{

}

void			Form::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->getSignGrade())
			GradeTooLowException();
		std::cout << PURPLE << bureaucrat.getName() << " signed " << this->getName() << "✒️" << DEFAULT << std::endl;
		this->sign = true;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "["<< this->getName() << "] An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}