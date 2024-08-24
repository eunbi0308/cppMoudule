#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	#ifdef DEBUG
		std::cout << GREY << "Bitcoin : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Bitcoin::Bitcoin(const Bitcoin &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Bitcoin : Copy constructor called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	*this = other;
}

Bitcoin &Bitcoin::operator=(const Bitcoin &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Bitcoin : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	return *this;
}

Bitcoin::~Bitcoin()
{
	#ifdef DEBUG
		std::cout << GREY << "Bitcoin : Destructor called" << DEFAULT << std::endl; 
	#endif
}

std::unordered_map<std::string, double> Bitcoin::getBcData()
{
    return this->bcData;
}

void Bitcoin::setBcData(std::unordered_map<std::string, double> data)
{
    this->bcData = data;
}

bool    checkDateValidation(const std::string &date)
{
    std::istringstream ss(date);
    std::tm ymd;

    ss >> std::get_time(&ymd, "%Y-%m-%d");
    if (ss.fail())
        return false;
    return true;
}

void Bitcoin::calcualteAndPrint(std::string filename)
{
    std::ifstream file(filename);

    if (file.is_open())
    {
        std::string line;
        getline(file, line); // Read and discard the first line
        while (getline(file, line))
        {
            std::stringstream ss(line);
            std::string date;
            // int         value;
            
            if (getline(ss, date, '|'))
            {
                if (checkDateValidation(date) == false)
                    std::cout << "Error: bad input" << " => " << date << '\n';
            }
            else
                std::cout << "Error: empty input." << '\n';
            
        }
    }    
}