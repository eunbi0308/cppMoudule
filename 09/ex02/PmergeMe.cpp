#include "PmergeMe.hpp"

void	printMainChain(auto &main)
{
	std::cout << YELLOW << "main chain:	";
	for (const auto &it : main)
		std::cout << it << " ";
	std::cout << "\n" << DEFAULT;
}

void	printNumbers(auto &main, auto &pending, int j)
{
	int mainSize = main.size();
	std::cout << "jacobsthal:	";
	for(int i = 1; i <= mainSize; i++)
	{
		if (i == j)
			std::cout << GREEN << i << " " << DEFAULT;
		else
			std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << GREEN << "pending[" << j << "] : " << pending[j] << '\n' << DEFAULT;
	printMainChain(main);
	std::cout << "\n";
}

void	printSortePairs(auto &pairs)
{
	std::cout << PURPLE << "___sorted pairs___\n";
	for (const auto& pair : pairs)
		std::cout << "[" << pair.first << ", " << pair.second << "]";
	std::cout << "\n\n" << DEFAULT;
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

	#ifdef PRINT
		std::cout << "main chain: ";
		for (const auto &it : main)
			std::cout << it << " ";
		std::cout << "\n";
		std::cout << "pending elements: ";
		for (const auto &it : pending)
			std::cout << it << " ";
		std::cout << "\n\n";
	#endif
	
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
		int next = prev * 2 + curr; // J(n) = J(n-2) * 2 + J(n-1)
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
	// the first pending element is smaller than the first main chain number.
	if (!pending.empty())
		main.insert(main.begin(), pending.front());
	// main.push_front(pending.front());
	int i = 1; 
	int jacobNum = 1;
	int pendingSize = pending.size();
	while (i < pendingSize)
	{
		for (int j = jacobsthalNumbers(jacobNum); j > 0 && j > jacobsthalNumbers(jacobNum - 1); --j)
		{
			#ifdef PRINT
				printMainChain(main);
			#endif
			auto it = pending.begin();
			if (j >= pendingSize)
				j = pendingSize - 1;
			std::advance(it, j);
			binarySearch(main, 0, main.size(), *it);
			++i;
			#ifdef PRINT
				printNumbers(main, pending, j);
			#endif

		}
		++jacobNum;
	}
	if (unpaired != -1)
		binarySearch(main, 0, main.size(), unpaired);
}

void	sortPairs(size_t i, auto &pairs)
{
	if (i == pairs.size())
		return ;
	for (size_t j = i + 1; j < pairs.size(); ++j)
	{
		if (pairs[i].first >= pairs[j].first)
			std::swap(pairs[i], pairs[j]);
	}
	sortPairs(++i, pairs);
}

auto makePairs(const auto &numbers, auto &pairs)
{
	// using valueType = typename Container::value_type;
	// using pairType = std::pair<valueType, valueType>;

	int	size = numbers.size();

	for (int i = 0; i < size; i += 2)
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

std::vector<int> vectorMergeInsertionSort(std::vector<int> &numbers)
{
	// Odd number
	int unpaired = -1;
	if (numbers.size() % 2 != 0)
	{
		unpaired = numbers.back();
		numbers.pop_back(); //remove the unpaired remaining number.
	}
	std::vector<std::pair<int, int>> pairs;
	// Sorting pairs
    makePairs(numbers, pairs);
    size_t i = 0;
	sortPairs(i, pairs);
	#ifdef PRINT
		printSortePairs(pairs)
	#endif
	std::vector<int> main, pending;
	makeMainChainAndPendingElements(pairs, main, pending);
	insertion(main, pending, unpaired);

	return main;	
}

std::deque<int> dequeMergeInsertionSort(std::deque<int> &numbers)
{
	// Odd number
	int unpaired = -1;
	if (numbers.size() % 2 != 0)
	{
		unpaired = numbers.back();
		numbers.pop_back(); //remove the unpaired remaining number.
	}
	std::deque<std::pair<int, int>> pairs;
	// Sorting pairs
    makePairs(numbers, pairs);
    size_t i = 0;
	sortPairs(i, pairs);
	#ifdef PRINT
		printSortePairs(pairs);
	#endif
	std::deque<int> main, pending;
	makeMainChainAndPendingElements(pairs, main, pending);
	insertion(main, pending, unpaired);

	return main;	
}