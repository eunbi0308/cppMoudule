#include "PmergeMe.hpp"
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

template <typename Container>
int    parseNumbers(const std::string &input, Container &container)
{
    std::istringstream iss(input);
    int number;
    int count = 0;

    while (iss >> number)
    {
        if (number < 0)
            throw std::runtime_error("Error: negative integer.");
        container.push_back(number);
        count++;
    }
    return count;
}

int main(int argc, char* argv[])
{
    try
    {
        std::string input = "";
        for(int i = 1; i < argc; ++i)
        {
            input += argv[i];
            if (i < argc - 1)
                input += ' ';
        }
        std::vector<int> intVector; 
        std::deque<int> intDeque;

        parseNumbers(input, intVector);
        parseNumbers(input, intDeque);

        clock_t vectorStart = clock();
        std::vector<int> vectorOutput = vectorMergeInsertionSort(intVector);
        clock_t vectorEnd = clock();
        double vectorElapsed = (double)(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1000.0;
        
        clock_t dequeStart = clock();
        std::deque<int> dequeOutput = dequeMergeInsertionSort(intDeque);
        clock_t dequeEnd = clock();
        double dequeElapsed = (double)(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000.0;

        // Check if the outputs are sorted.
        if (!(std::is_sorted(vectorOutput.begin(), vectorOutput.end())) 
            || !(std::is_sorted(dequeOutput.begin(), dequeOutput.end())))
            throw std::runtime_error("Error: incorrectly sorted.");

        // Print
        std::stringstream ss;
        for (int num : vectorOutput)
            ss << num << " ";

        std::cout << "Before: " << input << "\n";
        std::cout << "After: " << ss.str() << "\n";
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vectorElapsed << " us\n";
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << dequeElapsed << " us\n";     
    }
    catch (const std::exception &e)
    {
        std::cerr << RED <<  e.what() << "\n" << DEFAULT;
    }
    return 0;
}