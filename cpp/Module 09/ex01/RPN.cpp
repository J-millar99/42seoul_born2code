#include "RPN.hpp"
RPN::RPN() {}
RPN::RPN(const RPN &ref) { (void) ref; }
RPN &RPN::operator=(const RPN &ref) { (void) ref; return *this; }
RPN::~RPN(){}

RPN::RPN(const std::string &str)
{
    _stack = split(str, ' ');
}

std::stack<std::string> RPN::split(const std::string &str, char delimiter) {
    std::stack<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = str.find(delimiter);

    while (end != std::string::npos) {
        result.push(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    result.push(str.substr(start));
    return result;
}

void RPN::calculateRPN()
{
    if (_stack.size() < 3)
        std::cerr << "Error" << std::endl;
    std::stack<std::string> tmp;
    while ()
}
