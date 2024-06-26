#include "RPN.hpp"

void RPN::processError(const std::string &errorStr)
{
    std::cout << errorStr << std::endl;
    std::exit(1);
}

bool RPN::isDecimal(const std::string &token) const
{
    for (size_t idx = 0; idx < token.length(); ++idx)
        if (!std::isdigit(token[idx]))
            return false;
    return true;
}

bool RPN::isOperator(const std::string &token) const
{
    return !(token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/');
}

void RPN::printRPN() const
{
    if (_stack.size() == 1)
        std::cout << _stack.top() << std::endl;
    else
        processError("impossible expression");
}