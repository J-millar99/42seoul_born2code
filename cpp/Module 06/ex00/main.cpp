#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        std::cerr << "Argument Error" << std::endl;
    else if (!argv[1][0])
        argumentEmpty(argv[1]);
    else
        ScalarConverter::convert(argv[1]);
    return 0;
}

