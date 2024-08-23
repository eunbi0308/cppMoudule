#pragma once

# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define GREEN "\033[0;92m"
# define PURPLE	"\033[38;2;200;160;255m"
# define DEFAULT "\033[0m"

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(const T& container, int num)
{
	auto it = std::find(container.begin(), container.end(), num);
	if (it != container.end())
		return it;
	return container.end();
}