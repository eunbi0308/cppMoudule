#pragma once

# include <iostream>
# include <string>

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define BLUE "\033[38;5;38m"
# define DEFAULT "\033[0m"
# define PURPLE	"\033[38;2;200;160;255m"


class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal &);
		AAnimal &operator=(const AAnimal &);
		virtual ~AAnimal();

		virtual void	makeSound() const;
		std::string		getType() const;
};