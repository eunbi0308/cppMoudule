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

bool    isValidSyntax(const std::string& expression)
{
    std::stack<char> stack;

    for (char c : expression)
    {
        if (isdigit(c))
            stack.push(c);
        else if (isOperator(c))
        {
            if (stack.size() < 2)
                return false; // Operator needs at least two operands
            stack.pop();
            stack.pop();
            stack.push(c);
        }
    }

    return stack.size() == 1; // Valid RPN expression has exactly one left
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

TEST(Parsing, invalid_syntax)
{
    EXPECT_FALSE(isValidSyntax("1 + 1"));
    EXPECT_FALSE(isValidSyntax("1 +"));
    EXPECT_FALSE(isValidSyntax("8 9 * 9 - 9 - 9 - 4 - 1 + 1"));
}

TEST(Parsing, valid_syntax)
{
    EXPECT_TRUE(isValidSyntax("1"));
    EXPECT_TRUE(isValidSyntax("1 1 +"));
    EXPECT_TRUE(isValidSyntax("8 9 * 9 - 9 - 9 - 4 - 1 +"));
}

TEST(Parsing, invalid_char)
{
    EXPECT_THROW(parseExpression("(1 + 1)"), std::runtime_error);
    EXPECT_THROW(parseExpression("abc"), std::runtime_error);
    EXPECT_THROW(parseExpression("11 1 +"), std::runtime_error);
    EXPECT_THROW(parseExpression("11 1 +"), std::runtime_error);
}

TEST(Executing, calculate)
{
    RPN rpn;

    rpn.setStack(parseExpression("8 9 * 9 - 9 - 9 - 4 - 1 +"));
    EXPECT_EQ(rpn.calculate(), 42);

    rpn.setStack(parseExpression("7 7 * 7 -"));
    EXPECT_EQ(rpn.calculate(), 42);

    rpn.setStack(parseExpression("1 2 * 2 / 2 * 2 4 - +"));
    EXPECT_EQ(rpn.calculate(), 0);

    rpn.setStack(parseExpression("-"));
    EXPECT_THROW(rpn.calculate(), std::runtime_error);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}