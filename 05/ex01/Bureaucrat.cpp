#include "Bureaucrat.hpp" 
// #include <stdexcept>

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name), grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return this->grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& name) 
{
	out << name.getName() << ", bureaucrat grade " << name.getGrade();
	return out;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (grade == 1)
			throw GradeTooHighException("The grade is too high to increment. The highest grade is 1.");
		this->grade--;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "["<< this->getName() << "] An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (grade == 150)
			throw GradeTooLowException("The grade is too low to increment. The lowest grade is 150.");
		this->grade++;
	}
	catch(std::exception &e)
	{
		std::cerr << YELLOW << "[" << this->getName() << "] An exception occurred. " << e.what() << DEFAULT << std::endl;
	}
}