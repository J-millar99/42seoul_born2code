#include "RPN.hpp"

bool checkMathematicalExpression(std::string str)
{
    const std::string operators = "+-*/";
    for (size_t idx = 0; idx < str.length(); ++idx)
        if (!isdigit(str[idx]) || operators.find(str[idx]) != std::string::npos)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2 || !*argv || !**argv || checkMathematicalExpression(argv[1]))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    return 0;
}