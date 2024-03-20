#include "AForm.hpp"

AForm::AForm() : name("DEFAULT FORM"), sign(false), signGrade(1), executeGrade(1) 
{
	#ifdef DEBUG
		std::cout << GREY << "AForm : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

AForm::AForm(std::string name, int sGrade, int eGrade)
: name(name), sign(false), signGrade(sGrade), executeGrade(eGrade) 
{
	#ifdef DEBUG
		std::cout << GREY << "AForm : constructor called" << DEFAULT << std::endl; 
	#endif
	// Min & Max grade check
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException(this->name);
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException(this->name);
}

AForm::AForm(const AForm &other)
: name(other.getName()), sign(false), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade())
{
	#ifdef DEBUG
		std::cout << GREY << "AForm : Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	#ifdef DEBUG
		std::cout << GREY << "AForm : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	if (this != &other)
	{
		this->sign = other.sign;
		const_cast<std::string &>(this->name) = other.name;
		const_cast<int&>(this->signGrade) = other.signGrade;
		const_cast<int&>(this->executeGrade) = other.executeGrade;
	}
	return *this;
}

AForm::~AForm()
{
	#ifdef DEBUG
		std::cout << GREY << "AForm : Destructor called" << DEFAULT << std::endl; 
	#endif
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "["<< form.getName() << "]" 
		<< "\n- Target : '" << form.getTarget() << "'"
		<< "\n- The grade required to sign : " << form.getSignGrade() 
		<< "\n- The grade required to exeucte : " << form.getExecuteGrade()
		<< "\n- Sign staus : ";
	if (form.getSignStatus() == true)
		out << GREEN << "TRUE" << DEFAULT;
	else
		out << RED << "FALSE" << DEFAULT;
	return out;
}

/*** Getter ***/
std::string		AForm::getName() const
{
	return this->name;
}

int			AForm::getSignStatus() const
{
	return this->sign;
}

unsigned int	AForm::getSignGrade() const
{
	return this->signGrade;
}

unsigned int	AForm::getExecuteGrade() const
{
	return this->executeGrade;
}

void			AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException(bureaucrat.getName());
	else
		this->sign = true;
	
}

const char* AForm::GradeTooHighException::what() const throw()
{
	std::cerr << "[" << bureaucrat << "]";
	return ("'s grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	std::cerr << "[" << bureaucrat << "]";
	return ("'s grade is too low.");
}

// Check if the bureaucrat is capable to execute
void	AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException(bureaucrat.getName());
}