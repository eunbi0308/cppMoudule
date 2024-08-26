#pragma once
#include "Array.hpp"
#include <stdexcept>

class OutOfBoundsException : public std::exception
{
	private:
		const std::string	message;
	public:
		OutOfBoundsException(const std::string& message) : message(message) {}
		virtual const char *what() const throw()
		{
			return this->message.c_str();
		}
};

template <typename T>
Array<T>::Array() : ptr(new T[0]), arraySize(0)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Default constructor called" << DEFAULT << std::endl; 
	#endif
}

template <typename T>
Array<T>::Array(unsigned int n) : ptr(new T[n]), arraySize(n)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Array unsigned int constructor called" << DEFAULT << std::endl; 
	#endif
	for (size_t i = 0; i < this->size(); ++i)
	{
		(*this)[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array &other)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Copy constructor called" << DEFAULT << std::endl; 
	#endif

	this->arraySize = other.arraySize;
	this->ptr = new T[this->arraySize];
	for (unsigned int i = 0; i < this->arraySize; ++i)
	{
		ptr[i] = other.ptr[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	
	if (this != &other)
	{
		if (this->ptr != nullptr)
			delete[] this->ptr;
		this->arraySize = other.arraySize;
		this->ptr = new T[this->arraySize];
		for (unsigned int i = 0; i < this->arraySize; ++i)
		{
			this->ptr[i] = other.ptr[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	#ifdef STRUCTOR
		std::cout << GREY << "destructor called" << DEFAULT << std::endl; 
	#endif
	if (this->ptr != nullptr)
		delete[] this->ptr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Script operator overloading called" << DEFAULT << std::endl; 
	#endif
	
	if (index >= this->arraySize)
		throw OutOfBoundsException("Array index out of bounds");
	return this->ptr[index];
}


