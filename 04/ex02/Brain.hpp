#pragma once
# include <iostream>

# define BLUE "\033[38;5;38m"
# define DEFAULT "\033[0m"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		size_t getIdeasArraySize() const;
		void		setIdea(std::string idea, unsigned int index);
		std::string	getIdea(unsigned int index);
};