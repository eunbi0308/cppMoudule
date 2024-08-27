#include "Span.hpp"
#include <sstream>

Span::Span() : maxSize(__UINT32_MAX__)
{
	#ifdef DEBUG
		std::cout << GREY << "Span : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Span::Span(unsigned int N) : maxSize(N)
{
	#ifdef DEBUG
		std::cout << GREY << "Span : constructor called" << DEFAULT << std::endl; 
	#endif
	
	this->numbers.reserve(N);
}

Span::Span(const Span &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Span : Copy constructor called" << DEFAULT << std::endl; 
	#endif

	*this = other; 
}

Span &Span::operator=(const Span &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Span : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	
	if (this != &other)
	{
		this->maxSize = other.maxSize;
		this->numbers = other.numbers;
	}
	return *this;
}

Span::~Span()
{
	#ifdef DEBUG
		std::cout << GREY << "Span : Destructor called" << DEFAULT << std::endl; 
	#endif
}

void	Span::addNumber(int num)
{
	if (this->numbers.size() + 1 > this->maxSize)
		throw std::runtime_error("Exceeding maximum storage size");
	
	// Already N element exists in numbers
	if (std::find(this->numbers.begin(), this->numbers.end(), num) != this->numbers.end())
	{
		std::stringstream ss;
		ss << "'" << num << "' already exists";
		throw std::runtime_error(ss.str());
	}
	this->numbers.push_back(num);
}

void	Span::addNumbers(std::vector<int> nums)
{
	if (this->numbers.size() + nums.size() >= this->maxSize)
		throw std::runtime_error("Exceeding maximum storage size");

	for (const auto& i : nums)
	{
		if (std::find(this->numbers.begin(), this->numbers.end(), i) != this->numbers.end()
			|| std::find(nums.begin(), nums.end(), i) != nums.end())
		{
			std::stringstream ss;
			ss << "'" << i << "' already exists";
			throw std::runtime_error(ss.str());
		}
	}
	this->numbers.insert(this->numbers.end(), nums.begin(), nums.end());
}


// Finding the shortest span between all the stored numbers
int		Span::shortestSpan() const
{
	if (this->numbers.size() <= 1)
		throw std::runtime_error("Too less numbers to compare. At least two numbers needed.");

	std::vector<int> sortedNumbers = this->numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end()); // Sorting in ascending order.
	
	int minValue = std::abs(sortedNumbers[1] - sortedNumbers[0]); //init currMin value
	for (size_t i = 2; i < sortedNumbers.size(); ++i)
	{
		minValue = std::min(minValue, (sortedNumbers[i] - sortedNumbers[i - 1]));
	}
	return minValue;
}

// Finding the longest span between all the stored numbers
int		Span::longestSpan() const
{
	if (this->numbers.size() <= 1)
		throw std::runtime_error("Too less numbers to compare. At least two numbers needed.");

	std::vector<int> sortedNumbers = this->numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	return sortedNumbers.back() - sortedNumbers.front();
}

unsigned int		Span::getMaxSize()
{
	return this->maxSize;
}

std::vector<int>	Span::getNumbers()
{
	return this->numbers;
}