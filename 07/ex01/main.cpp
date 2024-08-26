#include <iostream>
#include "iter.hpp"

# define RED "\033[1;91m"
# define DEFAULT "\033[0m"

int main()
{
	{
		std::cout << RED << "----------------------------------" << DEFAULT << std::endl;
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		size_t len = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << RED << "Elements of an integer array" << DEFAULT << std::endl;
		iter(arr, len, print<int>);
		std::cout << std::endl << std::endl;

		std::cout << RED << "addOne function iteration" << DEFAULT << std::endl;
		iter(arr, len, addOne<int>);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << RED << "----------------------------------" << DEFAULT << std::endl;
		char	arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
		size_t len = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << RED << "Elements of a char array" << DEFAULT << std::endl;
		iter(arr, len, print<char>);
		std::cout << std::endl << std::endl;

		std::cout << RED << "changeValue function iteration" << DEFAULT << std::endl;
		iter(arr, len, changeValue<char>);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << RED << "----------------------------------" << DEFAULT << std::endl;
		std::string	arr[] = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii"};
		size_t len = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << RED << "Elements of a string array" << DEFAULT << std::endl;
		iter(arr, len, print<std::string>);
		std::cout << std::endl << std::endl;

		std::cout << RED << "changeValue function iteration" << DEFAULT << std::endl;
		iter(arr, len, changeValue<std::string>);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << RED << "----------------------------------" << DEFAULT << std::endl;
		double	arr[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
		size_t len = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << RED << "Elements of a double array" << DEFAULT << std::endl;
		iter(arr, len, print<double>);
		std::cout << std::endl << std::endl;

		std::cout << RED << "addOne function iteration" << DEFAULT << std::endl;
		iter(arr, len, addOne<double>);
		std::cout << std::endl << std::endl;
	}
}