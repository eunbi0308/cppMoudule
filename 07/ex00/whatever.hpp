#pragma once

/**
 * < Templates in C++ >
 * To pass the data type as a parameter so that we don't need to
 * write the same code for different data types.
 * Templates are expanded at compiler time(like macros).
 * the compiler does type-checking before template expansion.
 * Source code contains only function/class, but compiled code may conatain
 * multiple copies of the same fucntion/class.
 */
template <typename T>
void swap(T& a, T& b) 
{
    T tmp = a;
    a = b;
    b = tmp;
}

// min function template
template <typename T>
T min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

// max function template
template <typename T>
T max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}