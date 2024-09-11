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
#include <deque>
#include <list>
#include <type_traits>
#include <cassert>

// template <typename Container>
// class PmergeMe
// {
//     public:
//         PmergeMe();
//         // Pmerge(const std::string &str);
//         PmergeMe(const PmergeMe<Container> &other);
//         PmergeMe& operator=(const PmergeMe<Container> &other);
//         ~PmergeMe();

//         // Container mergeInsertionSort(const std::string &str);
// };
template <typename Container>
std::vector<int> mergeInsertionSort(Container& container);

// #include "PmergeMe.cpp"

#endif