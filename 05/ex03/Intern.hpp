#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		class InvalidFormException : public std::exception
		{
			private:
				const std::string	form;
			public:
				InvalidFormException(const std::string str) : form(str) {}
				const char *what() const throw();
		};

		AForm*	makeForm(std::string form, std::string target);
};