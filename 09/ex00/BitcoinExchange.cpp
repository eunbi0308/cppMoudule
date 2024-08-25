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

std::map<int, double> Bitcoin::getBcData()
{
	return this->bcData;
}

void Bitcoin::setBcData(std::map<int, double> data)
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

float   Bitcoin::exchange(int date, float value)
{
	auto it = this->bcData.begin();
	while (it->first <= date)
		it++;
	--it;
	if (it != this->bcData.end())
	{
		// std::cout << GREY << "date: " << it->first << '\n';
		// std::cout << "value : " << it->second << '\n' << DEFAULT;
		return it->second * value;
	}
	return -1;
}

// std::string trim(const std::string &str, const char c)
// {
// 	std::string result(str);

// 	auto const first{ result.find_first_not_of(c) };
// 	if (std::string::npos == first)
// 		return {};
// 	auto const	last{ result.find_last_not_of(c) };

// 	return result.substr(first, (last - first + 1));
// }

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
			std::string dateStr;
			float       value;
			
			if (getline(ss, dateStr, '|'))
			{
				if (checkDateValidation(dateStr) == false)
					std::cout << "Error: bad input => " << dateStr << '\n';
				else
				{
					ss >> value;
					if (value < 0)
						std::cout << "Error: not a positive number.\n";
					else if (value > 1000)
						std::cout << "Error: too large a number.\n";
					else
					{
						int dateInt = convertDate(dateStr);
						float exchangedValue = exchange(dateInt, value);
						std::cout << dateStr << "=> " << value << " = " << exchangedValue << "\n";
					}
				} 
			}
			else
				std::cout << "Error: empty input." << '\n';
			
		}
	}    
}
