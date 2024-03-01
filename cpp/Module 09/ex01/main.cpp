#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2 || !*argv || !**argv)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    return 0;
}