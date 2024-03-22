#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string	getTarget() const override {return target;}
		void		execute(Bureaucrat const& bureaucrat) const;
};