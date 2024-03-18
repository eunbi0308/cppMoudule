#pragma once

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define PURPLE	"\033[38;2;200;160;255m"
# define DEFAULT "\033[0m"

#include <iostream>
#include <string>
#include <exception>

/**
 * A custom class inherits all properties from the std::exception class.
 * The what() function from std::exception is overridden, 
 * which returns a custom error message string.
*/

class Bureaucrat
{
	private:
		const std::string	name;
		int		grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			private:
				const std::string	bureaucrat;
			public:
				GradeTooHighException(const std::string name) : bureaucrat(name) {}
				virtual const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			private:
				const std::string	bureaucrat;
			public:
				GradeTooLowException(const std::string name) : bureaucrat(name) {}
				virtual const char *what() const noexcept override;
		};

		std::string		getName() const;
		unsigned int	getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& name);

/**
 * Exceptions are run-time anomalies or anomalous conditions that occur during the execution of a program.
 * There are two types of exceptions:
 * 
 * 1.Synchronous
 * 2.Asynchronous (Eg: disc failure)
 * For this reason, C++ provides the following specialized keywords.
 * 
 * 	- try: denotes a block of code that has the potential to throw an exception.
 *  - catch: When an exception is thrown, catch denotes a block of code that is executed.
 *  - throw: Used to throw an exception to exception handler and keep track of the exceptions 
 * 			that a function raises but doesn't handle.
 * 
 * Using exception handling, you can separate error-handling code from normal code,
 * which makes code more readable and easier to maintain.
 * Exceptions allow programs to respond to unusual conditions (such as runtime errors
 * by delegating control to special routines known as handlers.
 * 
 * - How to Use try-catch to Define User-Defined Exceptions -
 * 
*/