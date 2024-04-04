#pragma once

template<typename T>
void swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}

// min function template
template<typename T>
T min(const T& a, const T& b)
{
    return (b < a) ? b : a;
}

// max function template
template<typename T>
T max(const T& a, const T& b)
{
    return (a < b) ? b : a;
}