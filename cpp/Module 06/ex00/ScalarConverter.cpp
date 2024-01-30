#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{ }

ScalarConverter::~ScalarConverter()
{ }

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
    (void) ref;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
    (void) ref;
    return *this;
}

void ScalarConverter::printErrorMessage(const std::string &msg)
{
    std::cerr << msg << std::endl;
}

// float ScalarConverter::convertFloat(std::string str)
// {

// }

// double ScalarConverter::convertDouble(std::string str)
// {

// }

void ScalarConverter::convert(const std::string &typeName)
{
    char castingChar = convertChar(typeName);
    printableChar(castingChar);
    // int castingInt = 0;
    // float castingFloat = 0;
    // double castingDouble = 0;
}
