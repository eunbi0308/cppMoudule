#include "Scalar.hpp"

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

	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Scalar : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif

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
	if (input.find('.') != std::string::npos)
	{
		if (input[0] == '.')
			return false;
	}
}

void	ScalarConverter::convert(const std::string input)
{
	char	c = 0;
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	std::string::size_type n;
	std::string::size_type f;

	n = input.find('.');
	f = input.find('f', input.length() - 1); //finding 'f' at the end of string.

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
		c = static_cast<char>(input[0]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (n == std::string::npos) // maximum possible value of size_type
	{
		i = stoi(input);
	}
}