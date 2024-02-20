#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        std::cerr << "Argument Error" << std::endl;
    else
        ScalarConverter::convert(argv[1]);
    // float fnum = 9223372036854775808;
    // std::cout << fnum;
    return 0;
}

