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
#include <stack>
#include <sstream>
#include <string>

class RPN
{
	private:
		std::stack<char> charStack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN& other);
		~RPN();
		void setStack(std::stack<char> stack);
		int calculate();
};

bool    isOperator(const char &c);