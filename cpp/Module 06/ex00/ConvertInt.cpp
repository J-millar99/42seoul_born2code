#include "ScalarConverter.hpp"

void ScalarConverter::printableInt(int &num)
{
    if ((0 <= num && num <= 8) || (14 <= num && num <= 31) || num == 127)
        printErrorMessage("int: Non displayble");
    else if (num < 0)
        printErrorMessage("int: impossible");
    else
        std::cout << "int: " << int << std::endl;
}

int ScalarConverter::convertInt(std::string str)
{

}