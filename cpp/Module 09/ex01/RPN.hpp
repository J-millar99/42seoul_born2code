#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stack>
class RPN : public std::stack<int>
{
    private:
        std::stack<int> _stack;
        RPN();
        RPN(const RPN &ref);
        RPN &operator=(const RPN &ref);
    public:
        ~RPN();
        RPN(const std::string &str);
        bool isDecimal(const std::string &token) const;
        bool isOperator(const std::string &token) const;
        static void processError(const std::string &errorStr);
        void printRPN() const;
        void parsingRPN(const std::string &str);
        void calculateRPN(char op);
};

#endif