#include "RPN.hpp"

RPN::RPN()
{
	#ifdef DEBUG
		std::cout << GREY << "RPN : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

RPN::RPN(const RPN &other)
{
	#ifdef DEBUG
		std::cout << GREY << "RPN : Copy constructor called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	#ifdef DEBUG
		std::cout << GREY << "RPN : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	return *this;
}

RPN::~RPN()
{
	#ifdef DEBUG
		std::cout << GREY << "RPN : Destructor called" << DEFAULT << std::endl; 
	#endif
}

void RPN::setStack(std::stack<char> stack)
{
	this->charStack = stack;
}

int RPN::calculate()
{
	if (this->charStack.empty())
		throw std::runtime_error("Empty stack.");

	int x, y;
	char	popped = this->charStack.top();
	this->charStack.pop();
	if (isOperator(popped) == true)
	{
		y = calculate();
		x = calculate();
		// std::cout << PINK << "y : " << y << " x : " << x << "\n" << DEFAULT;
		if (popped == '+')
			x += y;
		else if (popped == '-')
			x -= y;
		else if (popped == '*')
			x *= y;
		else if (popped == '/')
			x /= y;
	}
	else
	{
		// Converting char into integer.
		x = (popped - '0');
	}
	return x;
}