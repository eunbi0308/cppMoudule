#pragma once

# include <iostream>
# include <string>
# include "Brain.hpp"

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define DEFAULT "\033[0m"
# define PURPLE	"\033[38;2;200;160;255m"


class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void	makeSound() const;
		virtual Brain	&getBrain() const = 0;
		std::string		getType() const;
};