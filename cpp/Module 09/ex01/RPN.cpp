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

void RPN::parsingRPN(const std::string &str)
{
    std::string::size_type start = 0;
    std::string::size_type end = str.find(' ');
    std::string token;
    while (end != std::string::npos)
    {
        token = str.substr(start, end - start);
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
    long first = _stack.top(); _stack.pop();
    long second = _stack.top(); _stack.pop();
    if (op == '+') {
        long ret = first + second;
        if (ret > INT_MAX)
            processError("out of Int");
        _stack.push(first + second);
    }
    else if (op == '-') {
        long ret = second - first;
        if (ret < INT_MIN)
            processError("out of Int");
        _stack.push(second - first);
    }
    else if (op == '*') {
        long ret = first * second;
        if (ret > INT_MAX)
            processError("out of Int");
        _stack.push(first * second);
    }
    else if (op == '/')
    {
        if (first == 0)
            processError("nan");
        _stack.push(second / first);
    }
}
