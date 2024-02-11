#pragma once
# include <iostream>

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