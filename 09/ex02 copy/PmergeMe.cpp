#include "PmergeMe.hpp"
#include <type_traits>

// template <typename Container>
// PmergeMe<Container>::PmergeMe()
// {
// 	#ifdef STRUCTOR
// 		std::cout << GREY << "Default constructor called" << DEFAULT << std::endl; 
// 	#endif
// }

// template <typename Container>
// PmergeMe<Container>::PmergeMe(const PmergeMe<Container> &other)
// {
// 	#ifdef STRUCTOR
// 		std::cout << GREY << "Copy constructor called" << DEFAULT << std::endl; 
// 	#endif

// 	*this = other;
// }

// template <typename Container>
// PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &other)
// {
// 	#ifdef STRUCTOR
// 		std::cout << GREY << "Copy assignment operator called" << DEFAULT << std::endl; 
// 	#endif
	
// 	if (this != &other)
// 		return *this;
// }

// template <typename Container>
// PmergeMe<Container>::~PmergeMe()
// {
// 	#ifdef STRUCTOR
// 		std::cout << GREY << "destructor called" << DEFAULT << std::endl; 
// 	#endif
// }

template <typename Container>
auto makePairs(const Container &container, auto &pairs)
{
	// using valueType = typename Container::value_type;
	// using pairType = std::pair<valueType, valueType>;

	int	size = container.size();

	for (int i = 0; i < size; i += 2)
	{
		int first, second, max, min;
		first = container[i];
		second = container[i + 1];
		max = std::max(first, second);
		min = std::min(first, second); 
		pairs.push_back(std::make_pair(max, min)); // max number is located as first of a pair.
	}

	std::cout << PINK << "___pairs___\n";
	for (const auto& pair : pairs)
		std::cout << "(" << pair.first << ", " << pair.second << ")";
	std::cout << "\n\n" << DEFAULT;
	return pairs;
}

void	sortPairs(auto &pairs)
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

void	makeMainChainAndPendingElements(auto pairs, auto &main, auto &pending)
{
	// main : Mainchain of the pair. The bigger number of a pair.
	// pend : Pending elements. The smaller number of a pair.

	for (const auto &pair : pairs)
	{
		main.push_back(pair.first);
		pending.push_back(pair.second);
	}

	std::cout << "main chain: ";
	for (const auto &it : main)
		std::cout << it << " ";
	std::cout << "\n\n";
	std::cout << "pending elements: ";
	for (const auto &it : pending)
		std::cout << it << " ";
	std::cout << "\n\n";
	
}

int	jacobsthalNumbers(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	
	int prev = 0;
	int curr = 1;
	for (int i = 2; i < num; ++i)
	{
		int next = prev * 2 + curr;
		prev = curr;
		curr = next; 
	}
	return curr;
}

void	binarySearch(auto &main, int start, int len, int value)
{
	if (start >= len)
	{
		main.insert(main.begin() + start, value);
		return ;
	}
	int mid = ((len - start) / 2) + start;
	
	if (main[mid] > value)
		binarySearch(main, start, mid, value);
	else if (main[mid] < value)
		binarySearch(main, mid + 1, len, value);
	else
	{
		main.insert(main.begin() + mid, value);
		return ;
	}
}

void	insertion(auto &main, auto &pending, int unpaired)
{
	int pendingSize = pending.size();

	// the first pending element is smaller than the first main chain number.
	main.insert(main.begin(), pending.front());
	int i, jacobNum = 1;
	while (i < pendingSize)
	{
		for (int j = jacobsthalNumbers(jacobNum); j > 0 && j > jacobsthalNumbers(jacobNum - 1); --j)
		{
			auto it = pending.begin();
			if (j >= pendingSize)
				j = pendingSize - 1;
			std::advance(it, j);
			binarySearch(main, 0, main.size(), *it);
			++i;
		}
		++jacobNum;
	}
	if (unpaired != -1)
		binarySearch(main, 0, main.size(), unpaired);
}

template <typename Container>
std::vector<int> mergeInsertionSort(Container& container)
{
	// Odd number
	int unpaired = -1;
	if (container.size() % 2 != 0)
	{
		unpaired = container.back();
		container.pop_back(); //remove the unpaired remaining number.
	}

	std::vector<std::pair<int, int>> pairs;
	// Pairing
	if constexpr(std::is_same_v<Container, std::deque<int>>)
		std::deque<std::pair<int, int>> pairs;
	else
		std::list<std::pair<int, int>> pairs;

	makePairs(container, pairs);
	
	// Sorting pairs
	sortPairs(pairs);
	std::cout << PURPLE << "___sorted pairs___\n";
	for (const auto& pair : pairs)
		std::cout << "(" << pair.first << ", " << pair.second << ")";
	std::cout << "\n\n" << DEFAULT;

	Container main, pending;
	makeMainChainAndPendingElements(pairs, main, pending);
	insertion(main, pending, unpaired);

	return main;	
}
