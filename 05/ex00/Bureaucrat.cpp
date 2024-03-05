#include "Bureaucrat.hpp" 

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
		this->grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		this->grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
