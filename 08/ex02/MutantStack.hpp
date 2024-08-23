#pragma once

# define GREEN "\033[0;92m"
# define GREY "\033[0;90m"
# define PURPLE	"\033[38;2;200;160;255m"
# define PINK "\033[95m"
# define DEFAULT "\033[0m"

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

/**
 * The standard containers std::vector (including std::vector<bool>),
 * std::deque and std::list satisfy these requirements.
 * By default, if no container class is specified for a particular stack class instantiation, 
 * the standard container std::deque is used.
 * deque = double-ended queue(class template)
 * 
 * - Member object
 *  Container c : the underlying container(protected member function)
 */

template <class Type, class Container = std::deque <Type>>
class MutantStack : public std::stack<Type>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        /** 
         * Define aliases for the iterator types of ther underlying std::stack container.
        */
        using iterator = typename std::stack<Type>::container_type::iterator;
        using const_iterator = typename std::stack<Type>::container_type::const_iterator;

        // Iterator access functions
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator cbegin() { return this->c_begin(); }
        const_iterator cend() { return this->c_end(); }
};

#include "MutantStack.tpp"

