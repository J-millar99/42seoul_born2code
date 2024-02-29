#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>
class RPN : public std::stack<std::string>
{
    private:
        std::stack<std::string> _stack;
        RPN();
        RPN(const RPN &ref);
        RPN &operator=(const RPN &ref);
    public:
        RPN(const std::string &str);
        std::stack<std::string> split(const std::string &str, char sp);
        void calculateRPN();
        ~RPN();
};

#endif