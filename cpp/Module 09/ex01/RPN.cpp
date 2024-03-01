#include "RPN.hpp"
RPN::RPN() {}
RPN::RPN(const RPN &ref) { (void) ref; }
RPN &RPN::operator=(const RPN &ref) { (void) ref; return *this; }
RPN::~RPN(){}
RPN::RPN(const std::string &str)
{
    parsingRPN(str);
    printRPN();
}

void RPN::processError(const std::string &errorStr) const
{
    std::cerr << errorStr << std::endl;
    exit(1);
}

bool RPN::isDecimal(const std::string &token) const
{
    for (size_t idx = 0; idx < token.length(); ++idx)
        if (!isdigit(token[idx]))
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

void RPN::parsingRPN(const std::string &str)
{
    std::string::size_type start = 0;
    std::string::size_type end = str.find(' ');
    std::string token;
    while (end != std::string::npos)
    {
        token = str.substr(start, end - start);
        std::cout << "token : "+ token << std::endl;
        if (isDecimal(token))
            _stack.push(std::atoi(token.c_str()));
        else if (isOperator(token))
            calculateRPN(token[0]);
        else
            processError("undefined token : " + token);
        start = end + 1;
        end = str.find(' ', start);
    }
    token = str.substr(start);
    if (isDecimal(token))
        processError("impossible expression");
    else if (isOperator(token))
        calculateRPN(token[0]);
    else
        processError("undefined token : " + token);
}

void RPN::calculateRPN(char op)
{
    if (_stack.size() < 2)
        processError("impossible calculate");
    int first = _stack.top(); _stack.pop();
    int second = _stack.top(); _stack.pop();
    if (op == '+')
        _stack.push(first + second);
    else if (op == '-')
        _stack.push(second - first);
    else if (op == '*')
        _stack.push(first * second);
    else if (op == '/')
        _stack.push(second / first);
}
