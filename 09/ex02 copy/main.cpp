#include "PmergeMe.hpp"
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <sstream>


template <typename Container>
void    parseNumbers(const std::string &input, Container &container)
{
    std::istringstream iss(input);
    int number;

    while (iss >> number)
        container.push_back(number);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << RED << "USAGE : ./PmergeMe [numbers] \n" << DEFAULT;
        return EXIT_FAILURE;
    }
    std::string input = argv[1];
    std::cout << "Before: " << input << "\n";

    std::vector<int> intVector; 
    std::list<int>  intList;
    std::deque<int> intDeque;

    parseNumbers(input, intVector);
    // parseNumbers(input, intDeque);
    // parseNumbers(input, intList);

    mergeInsertionSort(intVector);
    // mergeInsertionSort(intDeque);
    // mergeInsertionSort(intList);
    
    // std::stringstream ss;
    // for (int num : output)
    // {
    //     ss << num << " ";
    // }

    // std::cout << "After: " << ss.str() << "\n";
    return 0;
}