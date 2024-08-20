#include "Span.hpp"
#include <random>

std::vector<int> generateUniqueRandomNumbers(unsigned int count, int min, int max);

int main()
{
    {
		std::cout << BLUE << "\n_____ Default test\n\n" << DEFAULT;
		try
		{
			std::cout << PURPLE << "Subject test\n" << DEFAULT;
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
    }
    {
		std::cout << BLUE << "\n_____ Basic test\n\n" << DEFAULT;
		try
		{
			std::cout << PURPLE << "Default contructor\n" << DEFAULT;
            Span defaultSpan;
            std::cout << "defaultSpan max size : " << defaultSpan.getMaxSize() << '\n';
            std::cout << GREY << "Adding numbers..." << '\n' << DEFAULT;
            std::vector<int> vectorInt = {7, 77, 8, 88, 9, 99};
            defaultSpan.addNumbers(vectorInt);
            
            std::cout << "Shortest : " << defaultSpan.shortestSpan() << std::endl;
            std::cout << "Longest : " << defaultSpan.longestSpan() << std::endl;

            std::cout << "\n";
            std::cout << PURPLE << "Copy contructor\n" << DEFAULT;
            Span sp1(5);
            std::cout << GREY << "Adding numbers..." << '\n' << DEFAULT;
            sp1.addNumbers(vectorInt);
            
            std::cout << YELLOW << "< sp1 >" << "\n" << DEFAULT;
            for (const auto& i: sp1.getNumbers())
                std::cout << i << " ";
            std::cout << "\n";
            std::cout << "sp1 max size : " << sp1.getMaxSize() << '\n';
            std::cout << "Shortest : " << defaultSpan.shortestSpan() << std::endl;
            std::cout << "Longest : " << defaultSpan.longestSpan() << std::endl;
            std::cout << "\n";
        
            std::cout << YELLOW << "< sp2 >" << "\n" << DEFAULT;
            Span sp2(sp1);
            for (const auto& i: sp2.getNumbers())
                std::cout << i << " ";
            std::cout << "\n";
            std::cout << "sp2 max size : " << sp2.getMaxSize() << '\n';
            std::cout << "Shortest : " << sp2.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp2.longestSpan() << std::endl;


                        std::cout << "\n";
            std::cout << PURPLE << "Copy operation assignment\n" << DEFAULT;
            Span sp3(7);
            std::cout << GREY << "Adding numbers..." << '\n' << DEFAULT;
            vectorInt = {7, 8, 27, -11, 77, -38, 99};
            sp3.addNumbers(vectorInt);
            
            std::cout << YELLOW << "< sp3 >" << "\n" << DEFAULT;
            for (const auto& i: sp3.getNumbers())
                std::cout << i << " ";
            std::cout << "\n";
            std::cout << "sp3 max size : " << sp3.getMaxSize() << '\n';
            std::cout << "Shortest : " << sp3.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp3.longestSpan() << std::endl;
            std::cout << "\n";

            std::cout << GREY << "Copying sp1 into sp3..." << '\n' << DEFAULT;
            sp3 = sp1;
            std::cout << YELLOW << "< sp3 >" << "\n" << DEFAULT;
            for (const auto& i: sp3.getNumbers())
                std::cout << i << " ";
            std::cout << "\n";
            std::cout << "sp3 max size : " << sp3.getMaxSize() << '\n';
            std::cout << "Shortest : " << sp3.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp3.longestSpan() << std::endl;
            std::cout << "\n";

        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
    }
    {
		std::cout << BLUE << "\n_____ Error test\n\n" << DEFAULT;
		try
		{
			std::cout << PURPLE << "No number\n" << DEFAULT;
            Span sp;
            std::cout << "Size : " << sp.getNumbers().size() << '\n';
            
            std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "One number\n" << DEFAULT;
            Span sp = Span(1);
            sp.addNumber(8);
            std::cout << "Size : " << sp.getNumbers().size() << '\n';
            
            std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "Exceeding max size (addNumber)\n" << DEFAULT;
            Span sp = Span(5);

            sp.addNumber(7);
            sp.addNumber(8);
            sp.addNumber(27);
            sp.addNumber(11);
            sp.addNumber(77);
            sp.addNumber(38);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "Exceeding max size (addNumbers)\n" << DEFAULT;
            Span sp = Span(5);
            std::vector<int> vectorInt = {8, 7, 9, -1, 22, 23};

            sp.addNumbers(vectorInt);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "Attempting to add existing number (addNumber)\n" << DEFAULT;
            Span sp = Span(5);
            sp.addNumber(7);
            sp.addNumber(8);
            sp.addNumber(7);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "Attempting to add existing number (addNumbers)\n" << DEFAULT;
            Span sp = Span(5);
            sp.addNumber(7);
            std::vector<int> vectorInt = {8, 7, -9};
            sp.addNumbers(vectorInt);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
    }
    {
        std::cout << BLUE << "\n_____ Large numbers test\n\n" << DEFAULT;
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "10000\n" << DEFAULT;
            Span sp;
            
            std::vector<int> randomNumbers = generateUniqueRandomNumbers(10000, 0, 10000);
            sp.addNumbers(randomNumbers);

            // for (const auto& i: sp.getNumbers())
            //     std::cout << i << " ";
            // std::cout << "\n";
            std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "100000\n" << DEFAULT;
            Span sp;
            
            std::vector<int> randomNumbers = generateUniqueRandomNumbers(100000, 0, 100000);
            sp.addNumbers(randomNumbers);

            // for (const auto& i: sp.getNumbers())
            //     std::cout << i << " ";
            // std::cout << "\n";
            std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
        try
		{
            std::cout << "\n";
			std::cout << PURPLE << "1000000\n" << DEFAULT;
            Span sp;
            
            std::vector<int> randomNumbers = generateUniqueRandomNumbers(1000000, 0, 1000000);
            sp.addNumbers(randomNumbers);

            // for (const auto& i: sp.getNumbers())
            //     std::cout << i << " ";
            // std::cout << "\n";
            std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
            std::cout << "Longest : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED <<  e.what() << "\n" << DEFAULT;
        }
    }
    return 0;
}

std::vector<int> generateUniqueRandomNumbers(unsigned int count, int min, int max)
{
    if (count > static_cast<unsigned int>(max - min + 1)) {
        throw std::invalid_argument("Count exceeds range of possible values");
    }
    std::vector<int> numbers(max - min + 1);
    std::iota(numbers.begin(), numbers.end(), min);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen);

    return std::vector<int>(numbers.begin(), numbers.begin() + count);
}