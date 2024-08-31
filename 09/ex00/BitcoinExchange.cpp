#include "BitcoinExchange.hpp"
#include <cctype>

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

std::map<int, float> Bitcoin::getBcData()
{
	return this->bcData;
}

void Bitcoin::setBcData(std::map<int, float> data)
{
	this->bcData = data;
}

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool    checkDateValidation(const std::string &date)
{
	std::istringstream ss(date);
	std::tm ymd;

	ss >> std::get_time(&ymd, "%Y-%m-%d");

	// Check if parsing was successful and mktime returns a valid 
	int year = ymd.tm_year + 1900;
	int month = ymd.tm_mon + 1;
	int day = ymd.tm_mday;
	if (ss.fail())
		return false;
	if (month == 2 && (day > 29 || (day == 29 && !isLeapYear(year))))
        return false; // Invalid day for February (non-leap year)

	return true;
}

float   Bitcoin::exchange(int date, float value)
{
	auto it = this->bcData.begin();
	while (it->first <= date && it != this->bcData.end())
		it++;
	--it;
	if (it != this->bcData.end())
	{
		// std::cout << GREY << "date: " << it->first << '\n';
		// std::cout << "value : " << std::fixed << std::setprecision(2) << it->second << '\n' << DEFAULT;
		return it->second * value;
	}
	return -1;
}

bool containsNonDigit(const std::string& str)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
		{
			if (str.length() == 1)
				return true;
			else if (str.length() > 1 && c != '.' && c != '-' && c != '+')
				return true;
		}	
	}
	return false;
}

bool	Bitcoin::isDateWithinRange(int dateInt)
{
	auto begin = this->bcData.begin();
	auto end = this->bcData.rbegin();
	int	beginDate = begin->first;
	int	endDate = end->first;
	if (dateInt < beginDate || dateInt > endDate)
	{
		std::cout << "Error: The date must be between " << beginDate <<  " and " << endDate << '\n';
		return false;
	}
	return true;

}

void Bitcoin::calculateAndPrint(std::string filename)
{
	std::ifstream file(filename);

	if (file.is_open())
	{
		std::string line;
		getline(file, line); // Read and discard the first line
		while (getline(file, line))
		{
			std::stringstream ss(line);
			std::string dateStr;
			float       value;
			
			if (getline(ss, dateStr, '|'))
			{
				if (checkDateValidation(dateStr) == false)
					std::cout << "Error: bad input => " << dateStr << '\n';
				else
				{
					std::string valueStr;
					ss >> valueStr;
					if (valueStr.empty())
						std::cout << "Error: The value is empty.\n";
					else if (containsNonDigit(valueStr) == true)
						std::cout << "Error: non-digit character is contained.\n";
					else
					{
						value = std::stof(valueStr);
						if (value < 0)
							std::cout << "Error: not a positive number.\n";
						else if (value > 1000)
							std::cout << "Error: too large a number.\n";
						else
						{
							int dateInt = convertDate(dateStr);
							if (isDateWithinRange(dateInt) == true)
							{
								float exchangedValue = exchange(dateInt, value);
								std::cout << dateStr << "=> " << value << " = " << exchangedValue << "\n";
							}
						}
					}
				} 
			}
			else
				std::cout << "Error: empty input." << '\n';
			
		}
	}    
}
