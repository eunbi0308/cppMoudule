#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string	getTarget() const override {return target;}
		void		execute(Bureaucrat const& bureaucrat) const;
};

#define ASCII_TREE "\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o. \n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o \n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' \n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' \n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' \n\
   `&%\\ ` /%&'    |.|        \\ '|8' \n\
       |o|        | |         | | \n\
       |.|        | |         | | \n\
    \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ \n\
"
