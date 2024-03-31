#pragma once

#include <iostream>
#include <math.h>

# define RED "\033[1;91m"
# define PURPLE	"\033[38;2;200;160;255m"
# define DEFAULT "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(const std::string str);
};
