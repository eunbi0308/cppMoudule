#include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
	private:
		const std::string	name;
		bool				sign;
		const unsigned int	signGrade;
		const unsigned int	executeGrade;

	public:
		Form(std::string name, bool sign, unsigned int signGrade, unsigned int getExecuteGrade);
		~Form() {}
		std::string		getName() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecuteGrade() const;
		void			beSigned(Bureaucrat name);
};