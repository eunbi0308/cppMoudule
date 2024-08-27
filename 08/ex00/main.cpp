#include "easyfind.hpp"
#include <list>
#include <deque>
#include <array>

template<typename T>
void	initContainerElements(T &container)
{
	for (size_t i = 0; i < 10; ++i)
	{
		container.push_back(i);
	}

}

template<typename T>
void	printElements(T &container)
{
	for (auto it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

int main()
{
	{
		std::cout << GREEN << "\n_____ Basic test (std::vector<int>)\n\n" << DEFAULT;
		try
		{
			std::vector<int> vectorInt;
			initContainerElements(vectorInt);
			std::cout << PURPLE << "Elements in vector<int>\n" << DEFAULT;
			printElements(vectorInt);
			std::cout << '\n';

			std::cout << PURPLE << "Find '1' in vector<int> => Found\n" << DEFAULT;
			auto it = easyfind(vectorInt, 1);
			if (it == vectorInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
			
			std::cout << PURPLE << "Find '10' in vector<int> => Error\n" << DEFAULT;
			it = easyfind(vectorInt, 10);
			if (it == vectorInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << DEFAULT;
		}
	}
	{
		std::cout << GREEN << "\n_____ Basic test (std::list<int>)\n\n" << DEFAULT;
		try
		{
			std::list<int> listInt;
			initContainerElements(listInt);
			std::cout << PURPLE << "Elements in list<int>\n" << DEFAULT;
			printElements(listInt);
			std::cout << '\n';

			std::cout << PURPLE << "Find '1' in listr<int> => Found\n" << DEFAULT;
			auto it = easyfind(listInt, 1);
			if (it == listInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
			
			std::cout << PURPLE << "Find '10' in list<int> => Error\n" << DEFAULT;
			it = easyfind(listInt, 10);
			if (it == listInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << DEFAULT;
		}
	}
	{
		std::cout << GREEN << "\n_____ Basic test (std:deque<int>)\n\n" << DEFAULT;
		try
		{
			std::deque<int> dequeInt;
			initContainerElements(dequeInt);
			std::cout << PURPLE << "Elements in deque<int>\n" << DEFAULT;
			printElements(dequeInt);
			std::cout << '\n';

			std::cout << PURPLE << "Find '1' in deque<int> => Found\n" << DEFAULT;
			auto it = easyfind(dequeInt, 1);
			if (it == dequeInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
			
			std::cout << PURPLE << "Find '10' in deque<int> => Error\n" << DEFAULT;
			it = easyfind(dequeInt, 10);
			if (it == dequeInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << DEFAULT;
		}
	}
	{
		std::cout << GREEN << "\n_____ Basic test (std:array<int>)\n\n" << DEFAULT;
		try
		{
			std::array<int, 10> arrayInt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			std::cout << PURPLE << "Elements in array<int>\n" << DEFAULT;
			printElements(arrayInt);
			std::cout << '\n';

			std::cout << PURPLE << "Find '1' in array<int> => Found\n" << DEFAULT;
			auto it = easyfind(arrayInt, 1);
			if (it == arrayInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
			
			std::cout << PURPLE << "Find '10' in array<int> => Error\n" << DEFAULT;
			it = easyfind(arrayInt, 10);
			if (it == arrayInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << DEFAULT;
		}
	}
	{
		std::cout << GREEN << "\n_____ First occurrence test \n\n" << DEFAULT;
		try
		{
			std::vector<int> vectorInt = {0, 3, 6, 9, 9, 15};
			std::cout << PURPLE << "Elements in vector<int>\n" << DEFAULT;
			for (auto it = vectorInt.begin(); it != vectorInt.end(); ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << '\n';

			std::cout << PURPLE << "Check the first '9' occurrence\n" << DEFAULT;
			auto it = easyfind(vectorInt, 9);
			std::cout << "The addrress of first occurrence : " << &vectorInt[3] << '\n';
			std::cout << "The addrress of second occurrence : " << &vectorInt[4] << '\n';
			std::cout << "The address of returned iterator : " << it.base() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << DEFAULT;
		}
	}
	return 0;
}