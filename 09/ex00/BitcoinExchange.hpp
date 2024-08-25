#pragma once

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define PURPLE	"\033[38;2;200;160;255m"
# define BLUE "\033[38;5;38m"
# define PINK "\033[95m"
# define DEFAULT "\033[0m"

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <regex>
#include <string>
#include <iterator>
#include <vector>

class Bitcoin
{
    private:
        std::map<int, double> bcData;

    public:
        Bitcoin();
        Bitcoin(const Bitcoin &other);
        Bitcoin& operator=(const Bitcoin& other);
        ~Bitcoin();
    
        std::map<int, double> getBcData();
        void    setBcData(std::map<int, double> data);
        void    calcualteAndPrint(std::string filename);
        float   exchange(int date, float value);
        // int     convertDate(const std::string& date);
};

int	convertDate(const std::string& date);