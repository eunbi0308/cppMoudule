#include <gtest/gtest.h>
#include "RPN.hpp"

bool    isOperator(const char &c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool    isValidChar(const std::string &str)
{
    for (char c : str)
    {
        if (isdigit(c) == false && isOperator(c) == false)
            return false;
    }
    return true;
}

std::stack<char>    parseExpression(const std::string& expression)
{
    std::stringstream   ss(expression);
    std::string         line;
    std::stack<char>     stack = {};

    while (std::getline(ss, line, ' '))
    {
        if (isValidChar(line) == false)
            throw std::runtime_error("Invalid character.");
        else if (line.length() > 1)
            throw std::runtime_error("Only one digit is allowed.");
        for (char c : line)
        {
            stack.push(c);
        }
    }
    return stack;
}

/**********************TESTS*************************/

TEST(Parsing, invalid_char)
{
    EXPECT_THROW(parseExpression("(1 + 1)"), std::runtime_error);
    EXPECT_THROW(parseExpression("abc"), std::runtime_error);
}

TEST(Parsing, calculate)
{
    RPN rpn;

    rpn.setStack(parseExpression("8 9 * 9 - 9 - 9 - 4 - 1 +"));
    EXPECT_EQ(rpn.calculate(), 42);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}