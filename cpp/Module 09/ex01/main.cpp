#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2 || !*argv || !**argv)
        RPN::processError("Error");
    RPN rpn(argv[1]);
    return 0;
}