#include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
	private:
		const std::string	name;
		bool				sign;
		const unsigned int	signGrade;
		const unsigned int	executeGrade;

	public:
		Form::Form(const Form &other);
		Form &Form::operator=(const Form &other);
		Form(std::string name, bool sign, unsigned int sGrade, unsigned int eGrade);
		Form() :signGrade(1), executeGrade(1) {}
		~Form() {}
		std::string		getName() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecuteGrade() const;
		void			beSigned(Bureaucrat name);
};