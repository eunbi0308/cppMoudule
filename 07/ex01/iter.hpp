#pragma once

template <typename T, typename Func>
void iter(T* array, size_t len, Func func)
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T>
void print(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void	addOne(T& num)
{
	num += 1;
	print(num);
}