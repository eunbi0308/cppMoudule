#include "Scalar.hpp"
#include <sstream>
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
	#ifdef DEBUG
		std::cout << GREY << "Scalar : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Scalar : Copy constructor called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Scalar : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	#ifdef DEBUG
		std::cout << GREY << "Scalar : Destructor called" << DEFAULT << std::endl; 
	#endif
}

// bool	inputChecker(const std::string input)
// {
// 	if (input.find('.') != std::string::npos)
// 	{
// 		if (input[0] == '.')
// 			return false;
// 	}
// }

void	printConvertedValues(const char c, const int i, const float f, const double d)
{
	std::cout << "char: ";
	if (c < 31 || c > 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convert(const std::string input)
{
	char	c = 0;
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	std::string::size_type n;
	std::string::size_type fPosition;

	n = input.find('.');
	fPosition = input.find('f', input.length() - 1); //finding 'f' at the end of string.

	//Pseudo literals
	if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf"
		|| input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
	{
		if (input == "nan" || input == "nanf")
			d = sqrt(-1.0);
		else
		{
			if (input[0] == '-')
				d = __DBL_MAX__ * -1000;
			else
				d = __DBL_MAX__ * 1000;
		}
	}
	else if (input.length() == 1 && !std::isdigit(static_cast<char>(input[0])))
	{
		//single character
		c = static_cast<char>(input[0]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (n == std::string::npos) // maximum possible value of size_type
	{
		i = stoi(input);

		std::stringstream ss;
		ss << i;
		// std::cout << "len : " << input.length() << "size : " << input.size() << std::endl;
		if (ss.str() != input)
		{
			if (i > 0 && fPosition == input.length() - 1)
			{
				c = static_cast<char>(i);
				f = static_cast<float>(i);
				d = static_cast<double>(i);
			}

		}
	}
	else
	{
		const char* str = input.c_str();
		char*	endptr = NULL;

		d = strtod(str, &endptr);
		if ((*endptr && !(*endptr == 'f' && endptr == &str[input.length() - 1])))
		{
			std::cout << "error" << std::endl;
			return ;
		}
		else
		{
			c = static_cast<char>(d); 
			i = static_cast<int>(d);
			f = static_cast<float>(d);

			std::cout << c << "||" << i << "||" << f << "||" << d << std::endl;
		}
	}
	printConvertedValues(c, i, f, d);
}
