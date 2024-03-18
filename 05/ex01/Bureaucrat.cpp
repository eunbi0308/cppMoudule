#include "Bureaucrat.hpp" 
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("DEFAULT"), grade(150)
{
	#ifdef DEBUG
		std::cout << GREY << "Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	#ifdef DEBUG
		std::cout << GREY << "Constructor called" << DEFAULT << std::endl; 
	#endif
	if (grade < 1)
		throw GradeTooHighException(this->name.c_str());
	else if (grade > 150)
		throw GradeTooLowException(this->name.c_str());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.grade)
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& name) 
{
	out << name.getName() << ", bureaucrat grade " << name.getGrade();
	return out;
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


/*** Memeber functions ***/
void	Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException(this->getName().c_str());
	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException(this->getName().c_str());
	this->grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{	
		// if (form.getSignStatus() == true)

		// else
			form.beSigned(*this);
		std::cout << PURPLE << "🖊️  " << getName() << " signed on Form " << form.getName() << "." << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << this->getName() << " couldn't sign " << form.getName() << ".\n" << e.what() << '\n' << DEFAULT;
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	std::cerr << "[" << bureaucrat << "] ";
	return ("The grade is too high. The grade range is 1 - 150.");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	std::cerr << "[" << bureaucrat << "] ";
	return ("The grade is too low. The grade range is 1 - 150.");
}