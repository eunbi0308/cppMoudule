#pragma once
#include "MutantStack.hpp"

template <class Type, class Container>
MutantStack<Type, Container>::MutantStack()
{
	#ifdef STRUCTOR
		std::cout << GREY << "Default constructor called" << DEFAULT << std::endl; 
	#endif
}

/**
 * c is a member variable of type Container that holds the underlying data of the stack.
 */
template <class Type, class Container>
MutantStack<Type, Container>::MutantStack(const MutantStack &other)
: std::stack<Type, Container>(other)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Copy constructor called" << DEFAULT << std::endl; 
	#endif

    this->c = other.c;
}

template <class Type, class Container>
MutantStack<Type, Container> &MutantStack<Type, Container>::operator=(const MutantStack &other)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	
	if (this != &other)
	{
        this->c = other.c;
	}
	return *this;
}

template <class Type, class Container>
MutantStack<Type, Container>::~MutantStack()
{
	#ifdef STRUCTOR
		std::cout << GREY << "destructor called" << DEFAULT << std::endl; 
	#endif
}


