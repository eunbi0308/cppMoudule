#pragma once

# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define BLUE "\033[38;5;38m"
# define PURPLE	"\033[38;2;200;160;255m"
# define DEFAULT "\033[0m"

# include <iostream>

template <typename T>
class Array
{
    private:
        T* ptr;
        unsigned int arraySize;
    public:
        Array();
        Array(unsigned int n);
		Array(const Array& other);
		Array &operator=(const Array& other);
        T& operator[](unsigned int index);
		~Array();
        unsigned int size() const
        {
            return this->arraySize;
        }
};

#include "Array.tpp"