#include "Bureaucrat.hpp" 
#include <stdexcept>

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name), grade(grade) {}

std::string	Bureaucrat::getName() const
{
	return this->name;
}

unsigned int	Bureaucrat::getGrade()
{
	return this->grade;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (grade == 1)
			throw GradeTooHighException();
		this->grade--;
	}
	catch(const  GradeTooHighException& e)
	{
		std::cerr << "The grade is too high to increment, " << e.what() << '\n';
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (grade == 150)
			throw GradeTooLowException();
		this->grade++;
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << "The grade is too low to decrement, " << e.what() << '\n';
	}
}
