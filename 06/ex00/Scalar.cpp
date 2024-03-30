#include "Scalar.hpp"
#include <sstream>
#include <cstdlib>
#include <limits>
#include <iomanip> // setprecision
#include <regex>

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

bool	inputChecker(const std::string input)
{
	// Non digit input
	if (input[0] != '-' && input.length() >= 1 && !std::isdigit(input[0]))
		return (false);
	// Out of range
	if (input.length() >= std::to_string(std::numeric_limits<long long int>::max()).length())
		return false;
	long long int number = std::stoll(input);
	if (number > std::numeric_limits<int>::max()
		|| number < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

bool areDecimalsZero(double number)
{
    std::string str = std::to_string(number);
    size_t decimalPos = str.find('.');

    if (decimalPos != std::string::npos)
	{
        std::string decimals = str.substr(decimalPos + 1);
        return std::regex_match(decimals, std::regex("0*"));
    }
    return true; // No decimal point found
}

void	printConvertedValues(const char c, const int i, const float f, const double d)
{
	/*** CHAR ***/
	std::cout << "char: ";
	if (c < 0 || c >= 127 || i == std::numeric_limits<int>::min())
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
	std::stringstream ss;
	std::cout << "float: ";
	if (areDecimalsZero(f) || f == 0)
	{
		ss << std::fixed << std::setprecision(1) << f;
		std::cout << ss.str() << "f" << std::endl;
		ss.str(std::string()); //clear ss for reuse
	}
	else
		std::cout << f << "f"<< std::endl;
	
	/*** DOUBLE ***/
	std::cout << "double: ";
	if (areDecimalsZero(d) || d == 0)
	{
		ss << std::fixed << std::setprecision(1) << d;
		std::cout << ss.str() << std::endl;
		ss.str(std::string());
	}
	else
		std::cout << d << std::endl;
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
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	std::string::size_type decimalpoint;
	decimalpoint = input.find('.');

	//Pseudo literals
	if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf"
		|| input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
	{
		PrintSpecialValues(input,f, d);
		return ;
	}
	if (!inputChecker(input))
	{
		std::cerr << RED << "error" << DEFAULT << std::endl;
		return ;
	}
	else if (input.length() == 1 && !std::isdigit(input[0]))
	{
		//single character
		c = static_cast<char>(input[0]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (decimalpoint == std::string::npos) //no decimal point
	{
		i = stoi(input);
		c = static_cast<char>(i);
        f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else // convert double input
	{
		const char* str = input.c_str();
		char*		endptr = NULL;

		d = strtod(str, &endptr);
		if ((*endptr && !(*endptr == 'f' && endptr == &str[input.length() - 1])))
		{
			std::cerr << RED << "error" << DEFAULT << std::endl;
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
