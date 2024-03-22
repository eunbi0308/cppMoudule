#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			executeGrade;

	public:
		AForm();
		AForm(std::string name, int sGrade, int eGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		// because C++ does not automatically call derived class destructors
		// when you delete a base class pointer that points to a derived class object.
		// If the destructor in the base class is not virtual, then only the base class 
		// destructor will be called, leading to incomplete destruction of the object.
		// This can result in undefined behavior, especially if the derived class has resources 
		//  that need to be cleaned up.
		virtual ~AForm();

		class GradeTooHighException : public std::exception
		{
			private:
				const std::string	bureaucrat;
			public:
				GradeTooHighException(const std::string name) : bureaucrat(name) {}
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				const std::string	bureaucrat;
			public:
				GradeTooLowException(const std::string name) : bureaucrat(name) {}
				const char *what() const throw();;
		};

		std::string		getName() const;
		int				getSignStatus() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecuteGrade() const;
		void			beSigned(Bureaucrat &name);\

		virtual std::string	getTarget() const = 0;
		virtual void		execute(Bureaucrat const& bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& name);