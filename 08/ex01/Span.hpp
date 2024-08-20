#pragma once

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define PURPLE	"\033[38;2;200;160;255m"
# define BLUE "\033[38;5;38m"
# define PINK "\033[95m"
# define DEFAULT "\033[0m"

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int 		maxSize;
		std::vector<int>	numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span &operator=(const Span& other);
		~Span();

		void	addNumber(int num);
		void	addNumbers(std::vector<int> nums);
		int		shortestSpan() const;
		int		longestSpan() const;

		unsigned int		getMaxSize();
		std::vector<int>	getNumbers();

};