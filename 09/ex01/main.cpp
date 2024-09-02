#include "RPN.hpp"

/**
 * Reverse Polish Notation(RPN)
 * aka Inverted Polish mathematical expression
 * How it works: 
 * 1. Operands are placed on a stack.
 * 2. Operators are applied to the top two operands on the stack, and the result is pushed back onto the stack.
 * Example:
 * To evaluate the expression (2 + 3) * 4
 * 1. 2 3 + 4 *
 * 2. 2 3 (operands on the stack)
 * 3. 5 (2 + 3 = 5, result pushed)
 * 4. 5 4 (operands on the stack)
 * 5. 20 (5 * 4 = 20, result pushed)
 */

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

    if (isValidSyntax(expression) == false)
        throw std::runtime_error("Invalid syntax.");
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

int main(int argc, char **argv)
{
    try 
    {
        if (argc != 2)
            throw std::runtime_error("USAGE : ./RPN \"expression\"");
        std::string expression = argv[1];

        RPN rpn;
        rpn.setStack(parseExpression(expression));
        // std::stack<char> printStack = parseExpression(expression);
        // std::stack<char> temp;
        // while (!printStack.empty()) 
        // {
        //     temp.push(printStack.top());
        //     printStack.pop();
        //     std::cout << temp.top() << " ";
        // }
        std::cout << "\n";
        int result = rpn.calculate();
        std::cout << GREEN << result << '\n' << DEFAULT;
    } catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << '\n' << DEFAULT;
    }
    return 0;
}