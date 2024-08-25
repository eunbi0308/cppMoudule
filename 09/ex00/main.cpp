#include "BitcoinExchange.hpp"

void    checkFileValidation(std::string filename)
{
	std::ifstream file(filename);

	if (file.is_open() == false)
	{
		std::stringstream ss;
		ss << "could not open '" << filename << "'";
		throw std::runtime_error(ss.str());
	}
	else if (file.seekg(0, std::ios::end).tellg() == 0)
	{
		std::stringstream ss;
		ss << filename << " is empty.";
		throw std::runtime_error(ss.str());
	}
}

int	convertDate(const std::string& date)
{
	std::regex regex("-");
	std::string result = date;
	result = std::regex_replace(result, regex, "");

	return std::stoi(result);
}

std::map<int, double>    parseDatabase(std::string database)
{
	checkFileValidation(database);

	std::map<int, double> data = {};
	std::ifstream file(database);

	if (file.is_open())
	{
		std::string line;
		getline(file, line); // Read and discard the first line
		while (getline(file, line))
		{
			std::stringstream ss(line);
			std::string dateStr;
			double exchangeRate;
			
			if (getline(ss, dateStr, ',') && (ss >> exchangeRate))
			{
				int date = convertDate(dateStr);
				data[date] = exchangeRate;
			}
		}
	}
	return data;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << '\n';
		return 1;
	}
	try
	{
		std::string filename = argv[1];
		checkFileValidation(filename);

		std::string database = "data.csv";
		Bitcoin bc;
		std::map<int, double> data = parseDatabase(database);
		if (!data.empty())
			bc.setBcData(data);
		bc.calcualteAndPrint(filename);
		// for (const auto& entry : bc.getBcData())
		// {
		//     std::cout << "date : " << entry.first << "|" << "\n";
		//     std::cout << "rate : " << entry.second << "|" << "\n";
		// }
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << "\n";
	}
	return 0;
}