#include "PmergeMe.hpp"

template <typename T, typename Container>
PmergeMe<T, Container>::PmergeMe()
{
	#ifdef STRUCTOR
		std::cout << GREY << "Default constructor called" << DEFAULT << std::endl; 
	#endif
}

template <typename T, typename Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe<T, Container> &other)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other;
}

template <typename T, typename Container>
PmergeMe<T, Container> &PmergeMe<T, Container>::operator=(const PmergeMe<T, Container> &other)
{
	#ifdef STRUCTOR
		std::cout << GREY << "Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	
	if (this != &other)
		return *this;
}

template <typename T, typename Container>
PmergeMe<T, Container>::~PmergeMe()
{
	#ifdef STRUCTOR
		std::cout << GREY << "destructor called" << DEFAULT << std::endl; 
	#endif
}

template <typename T, typename Container>
Container<T> makePairs(Container &numbers)
{
	size_t	size = numbers.size();
	Container<std::pair<int, int>> pairs;

	for (size_t i = 0; i < size; i += 2)
	{
		int first, second, max, min;
		first = numbers[i];
		second = numbers[i + 1];
		max = std::max(first, second);
		min = std::min(first, second); 
		pairs.push_back(std::make_pair(max, min)); // max number is located as first of a pair.
	}
	return pairs;
}

template <typename Container>
auto	sortPairs(Container &pairs)
{
	static size_t i = 0;
	std::cout << BLUE << "static i : " << i << '\n';

	if (i == pairs.size() - 1)
		return ;

	for (size_t j = i + 1; j < pairs.size(); ++j)
	{
		if (pairs[i].first < pairs[j].first)
			std::swap(pairs[i], pairs[j]);
	}
	sortPairs(pairs);
}

template <typename Container>
auto mergeInsertionSort(const Container& container)
{
	// Odd number
	int unpaired = 0;
	if (numbers.size() % 2 != 0)
	{
		unpaired = numbers.back();
		numbers.pop_back(); //remove the unpaired remaining number.
	}

	// Pairing
	Container pairs = makePairs(numbers);
	sortPairs(pairs);

	// Sorting pairs

	return numbers;	
}

