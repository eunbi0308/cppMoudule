#ifndef PMERGEME_H
#define PMERGEME_H

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define PURPLE	"\033[38;2;200;160;255m"
# define BLUE "\033[38;5;38m"
# define PINK "\033[95m"
# define DEFAULT "\033[0m"

#include <iostream>
#include <vector>

// template <class T, class Alloc = std::allocator<T>>
// class PmergeMe : public std::allocator<T>
// {
template <typename T, class Container>
class PmergeMe : public Container<T>
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        Container<T> mergeInsertionSort(const std::string &str); 
};

#include "PmergeMe.cpp"

#endif