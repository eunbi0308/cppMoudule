#include "easyfind.hpp"

int main()
{
	{
		std::cout << GREEN << "\n_____ Basic test\n\n" << DEFAULT;
		try
		{
			std::vector<int> vectorInt = {0, 3, 6, 9, 12, 15};
			std::cout << PURPLE << "___ Elements in vector<int>\n" << DEFAULT;
			for (auto it = vectorInt.begin(); it != vectorInt.end(); ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << '\n';

			std::cout << PURPLE << "___ Find '1' in vector<int>\n" << DEFAULT;
			auto it = easyfind(vectorInt, 3);
			if (it == vectorInt.end())
				throw std::runtime_error("Value not found in the container.");
			else
				std::cout << "Found " << *it << '\n';
			
			std::cout << PURPLE << "___ Find '10' in vector<int>\n" << DEFAULT;
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
		std::cout << GREEN << "\n_____ First occurrence test \n\n" << DEFAULT;
		try
		{
			std::vector<int> vectorInt = {0, 3, 6, 9, 9, 15};
			std::cout << PURPLE << "___ Elements in vector<int>\n" << DEFAULT;
			for (auto it = vectorInt.begin(); it != vectorInt.end(); ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << '\n';

			std::cout << PURPLE << "___ Check the first '9' occurrence\n" << DEFAULT;
			auto it = easyfind(vectorInt, 9);
			if (it != vectorInt.begin() + 3)
				throw std::runtime_error("Incorrect first occurrence of value.");
			else
				std::cout << "Found " << *it << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << DEFAULT;
		}
	}
	return 0;
}