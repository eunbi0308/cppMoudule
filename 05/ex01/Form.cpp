#include "Form.hpp"

Form::Form() : name("DEFAULT FORM"), sign(false), signGrade(1), executeGrade(1) 
{
	#ifdef DEBUG
		std::cout << GREY << "Form : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Form::Form(std::string name, int sGrade, int eGrade)
: name(name), sign(false), signGrade(sGrade), executeGrade(eGrade) 
{
	#ifdef DEBUG
		std::cout << GREY << "Form : constructor called" << DEFAULT << std::endl; 
	#endif
	// Min & Max grade check
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException(this->name);
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException(this->name);
}

Form::Form(const Form &other)
: sign(false), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade())
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
	if (this != &other)
	{
		const_cast<std::string &>(this->name) = other.name;
		this->sign = other.sign;
		const_cast<int&>(this->signGrade) = other.signGrade;
		const_cast<int&>(this->executeGrade) = other.executeGrade;
	}
	return *this;
}

Form::~Form()
{
	#ifdef DEBUG
		std::cout << GREY << "Form : Destructor called" << DEFAULT << std::endl; 
	#endif
}

std::ostream& operator<<(std::ostream& out, const Form& name)
{
	out << "Form ["<< name.getName() << "] The grade required to sign : " << name.getSignGrade() 
		<< "\n	 The grade required to exeucte : " << name.getExecuteGrade()
		<< "\n	 Sign staus : ";
	if (name.getSignStatus() == true)
		out << GREEN << "TRUE" << DEFAULT;
	else
		out << GREY << "FALSE" << DEFAULT;
	return out;
}

/*** Getter ***/
std::string		Form::getName() const
{
	return this->name;
}

int			Form::getSignStatus() const
{
	return this->sign;
}

unsigned int	Form::getSignGrade() const
{
	return this->signGrade;
}

unsigned int	Form::getExecuteGrade() const
{
	return this->executeGrade;
}

void			Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException(bureaucrat.getName());
	else
		this->sign = true;
	
}

const char* Form::GradeTooHighException::what() const throw()
{
	std::cerr << "[" << bureaucrat << "]";
	return ("'s grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	std::cerr << "[" << bureaucrat << "]";
	return ("'s grade is too low.");
}