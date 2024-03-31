#pragma once

# define RED "\033[1;91m"
# define DEFAULT "\033[0m"

#include <iostream>

class Base
{
	public:
		virtual ~Base() {};
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);