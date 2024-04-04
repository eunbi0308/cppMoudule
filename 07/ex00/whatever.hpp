#pragma once

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