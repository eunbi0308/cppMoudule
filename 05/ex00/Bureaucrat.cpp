#include "Bureaucrat.hpp" 
// #include <stdexcept>

Bureaucrat::Bureaucrat()
{
	#ifdef DEBUG
		std::cout << GREY << "Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name), grade(grade)
{
	#ifdef DEBUG
		std::cout << GREY << "Initialized" << DEFAULT << std::endl; 
	#endif
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Copy assignment operator called" << DEFAULT << std::endl; 
	#endif

	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	#ifdef DEBUG
		std::cout << GREY << "Destructor called" << DEFAULT << std::endl; 
	#endif
}

/*** Getter ***/
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

/*** Memeber functions ***/
void	Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException(this->name.c_str(), "The grade is too high to increment. The highest grade is 1.");
	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException(this->name.c_str(), "The grade is too low to increment. The lowest grade is 150.");
	this->grade++;
}