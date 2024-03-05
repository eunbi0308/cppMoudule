#pragma once

#include <iostream>
#include <string>

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