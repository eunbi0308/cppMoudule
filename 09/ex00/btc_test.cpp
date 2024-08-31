#include <gtest/gtest.h>
#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>

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

std::map<int, float>    parseDatabase(std::string database)
{
	checkFileValidation(database);

	std::map<int, float> data = {};
	std::ifstream file(database);

	if (file.is_open())
	{
		std::string line;
		getline(file, line); // Read and discard the first line
		while (getline(file, line))
		{
			std::stringstream ss(line);
			std::string dateStr;
			float exchangeRate;
			
			if (getline(ss, dateStr, ',') && (ss >> exchangeRate))
			{
				int date = convertDate(dateStr);
				data[date] = exchangeRate;
			}
		}
	}
	return data;
}

/************************ TESTS ******************************/

/** Parsing **/
TEST(Parsing, empty_file)
{
    EXPECT_THROW(checkFileValidation("/error_files/empty.csv"), std::runtime_error);
    EXPECT_THROW(checkFileValidation("/error_files/empty.txt"), std::runtime_error);
}

TEST(Parsing, no_permission)
{
    EXPECT_THROW(checkFileValidation("/error_files/no_permission.csv"), std::runtime_error);
    EXPECT_THROW(checkFileValidation("/error_files/no_permission.txt"), std::runtime_error);
}

TEST(Parsing, wrong_file_name)
{
    EXPECT_THROW(checkFileValidation("/error_files/nothing"), std::runtime_error);
}

TEST(Parsing, convertDate_func)
{
    EXPECT_EQ(convertDate("2011-01-01"), 20110101);
    EXPECT_EQ(convertDate("0000-01-01"), 101);
    EXPECT_EQ(convertDate("2222-22-22"), 22222222);
    EXPECT_EQ(convertDate("2010-10-10"), 20101010);
}

/** Exchanged value **/
TEST(Exchange, correct)
{
    Bitcoin bc;
    std::map<int, float> data = parseDatabase("../data.csv");
    bc.setBcData(data);
    EXPECT_NEAR(bc.exchange(20110103, 3), 0.9, 0.01);
    EXPECT_NEAR(bc.exchange(20200308, 1), 8039.38, 0.01);
    EXPECT_NEAR(bc.exchange(20200309, 1), 8039.38, 0.01);
    EXPECT_NEAR(bc.exchange(20200310, 1), 8039.38, 0.01);
}

/** Output **/

std::string captureOutputToFile(std::string filename)
{
    Bitcoin bc;
    std::map<int, float> data = parseDatabase("../data.csv");
    bc.setBcData(data);

    std::string tempFileName = "temp_output.txt";
    std::ofstream outFile(tempFileName);
    std::streambuf* oldCoutBuf = std::cout.rdbuf();
    std::cout.rdbuf(outFile.rdbuf());

    // Call the function that produces the output
    bc.calculateAndPrint(filename);

    std::cout.rdbuf(oldCoutBuf);
    outFile.close();

    std::ifstream inFile(tempFileName);
    std::string output;
    std::string line;
    while (std::getline(inFile, line))
    {
        output += line + "\n";
    }
    inFile.close();

    remove(tempFileName.c_str()); // Delete the temporary file
    return output;
}

class OutputCaptureFixture : public testing::Test
{
    public:
        void SetUp() override {
            outFile.open("test.txt");
            oldCoutBuf = std::cout.rdbuf();
            std::cout.rdbuf(outFile.rdbuf());
        }

        void TearDown() override {
            std::cout.rdbuf(oldCoutBuf);
            outFile.close();
        }

    protected:
        std::ofstream outFile;
        std::streambuf* oldCoutBuf;
};

TEST_F(OutputCaptureFixture, subject_test)
{
    std::string output = captureOutputToFile("../input.txt");

    std::stringstream ss; 
    ss << "2011-01-03 => 3 = 0.9\n"
        << "2011-01-03 => 2 = 0.6\n"
        << "2011-01-03 => 1 = 0.3\n"
        << "2011-01-03 => 1.2 = 0.36\n"
        << "2011-01-09 => 1 = 0.32\n"
        << "Error: not a positive number.\n"
        << "Error: bad input => 2001-42-42\n"
        << "2012-01-11 => 1 = 7.1\n"
        << "Error: too large a number.\n";
    std::string correctResult = ss.str();

    EXPECT_EQ(output, correctResult);
}

TEST_F(OutputCaptureFixture, error_handling)
{
    std::string output = captureOutputToFile("../input2.txt");

    std::stringstream ss;
    ss << "2011-01-03 => 3 = 0.9\n"
        << "2011-01-03 => 2 = 0.6\n"
        << "2011-01-03 => 1 = 0.3\n"
        << "2011-01-03 => 1.2 = 0.36\n"
        << "2011-01-09 => 1 = 0.32\n"
        << "Error: not a positive number.\n"
        << "2012-01-11 => 1 = 7.1\n"
        << "Error: non-digit character is contained.\n"
        << "Error: non-digit character is contained.\n"
        << "2012-02-29 => 2 = 9.96\n"
        << "Error: bad input => 2001-42-42\n"
        << "Error: bad input => 2011-02-31 \n" 
        << "Error: bad input => 2011-13-31 \n"
        << "Error: bad input => 1 \n"
        << "Error: bad input => abc \n"
        << "2012-01-11 => 1 = 7.1\n"
        << "Error: too large a number.\n"
        << "2022-03-29 => 1 = 47115.9\n"
        << "Error: non-digit character is contained.\n"
        << "Error: non-digit character is contained.\n"
        << "Error: The date must be between 20090102 and 20220329\n"
        << "Error: The date must be between 20090102 and 20220329\n"
        << "Error: The value is empty.\n";

    std::string correctResult = ss.str();

    EXPECT_EQ(output, correctResult);

}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
