#pragma once

#include <iostream>
#include <string>

class GradeTooHighException : public std::exception
{
	public:
    const char* what() const noexcept override 
	{
        return "The highest grade is 1.";
    }
};

class GradeTooLowException : public std::exception 
{
	public:
    const char* what() const noexcept override
	{
        return "The lowest grade is 150.";
    }
};

class Bureaucrat
{
	private:
	const std::string	name;
	unsigned int		grade;

	public:
	Bureaucrat() {}
	~Bureaucrat() {}
	Bureaucrat(std::string name, unsigned int grade);

	std::string		getName() const;
	unsigned int	getGrade();
	void			incrementGrade();
	void			decrementGrade();
};