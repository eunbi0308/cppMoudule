#include "Scalar.hpp"
#include <sstream>
#include <cstdlib>
#include <limits>

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
	/*** CHAR ***/
	std::cout << "char: ";
	if (c < 0 || c > 127 || c == '\0')
		std::cout << "impossible" << std::endl;
	else if (c >= 0 && c <= 31)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

	/*** INT ***/
	std::cout << "int: ";
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	
	/*** FLOAT ***/
	std::cout << "float: " << f << "f"<< std::endl;

	/*** DOUBLE ***/
	std::cout << "double: " << d << std::endl;
}

void	PrintSpecialValues(const std::string input, float f, double d)
{
	if (input == "nan" || input == "nanf")
	{
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
	}
	else
	{
		if (input[0] == '-')
		{
			f = __FLT_MAX__ * -10;
			d = __DBL_MAX__ * -10;
		}
		else
		{
			f = __FLT_MAX__ * 10;
			d = __DBL_MAX__ * 10;
		}
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f"<< std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convert(const std::string input)
{
	char	c = 0;
	long long		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	std::string::size_type decimalpoint;
	std::string::size_type fPosition;

	decimalpoint = input.find('.');
	fPosition = input.find('f', input.length() - 1); //finding 'f' at the end of string.

	// std::cout << RED << input << DEFAULT << std::endl;

	//Pseudo literals
	if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf"
		|| input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
	{
		PrintSpecialValues(input,f, d);
		return ;
	}
	else if (input.length() == 1 && !std::isdigit(input[0]))
	{
		std::cout << RED << "HERE 1" << DEFAULT << std::endl;
		//single character
		c = static_cast<char>(input[0]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);

		// std::cout << c << "||" << i << "||" << f << "||" << d << std::endl;
	}
	else if (decimalpoint == std::string::npos) //no decimal point
	{
		std::cout << RED << "HERE 2" << DEFAULT << std::endl;
		i = stoi(input);

		std::stringstream ss;
		ss << i;
		if (i > 0)
		{
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
	}
	else
	{
		std::cout << RED << "HERE 3" << DEFAULT << std::endl;
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
		}
	}
	printConvertedValues(c, i, f, d);
}
