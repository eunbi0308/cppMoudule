#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			executeGrade;

	public:
		Form();
		Form(std::string name, int sGrade, int eGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

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
		void			beSigned(Bureaucrat &name);
};

std::ostream& operator<<(std::ostream& out, const Form& name);