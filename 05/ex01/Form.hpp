#include "Bureaucrat.hpp"

class Bureaurat;

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const unsigned int	signGrade;
		const unsigned int	executeGrade;

	public:
		Form();
		Form(std::string name, bool sign, unsigned int sGrade, unsigned int eGrade);
		Form::Form(const Form &other);
		Form &Form::operator=(const Form &other);
		~Form();
		std::string		getName() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecuteGrade() const;
		void			beSigned(Bureaucrat name);
};