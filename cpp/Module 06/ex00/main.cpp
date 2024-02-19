#include "ScalarConverter.hpp"
#include <cstdio>


int main(int argc, char *argv[])
{
    if (argc != 2)
        std::cerr << "Argument Error" << std::endl;
    else
        ScalarConverter::convert(argv[1]);
    
    return 0;
}