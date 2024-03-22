#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		std::string	getTarget() const override {return target;}
		void		execute(Bureaucrat const& bureaucrat) const;
};