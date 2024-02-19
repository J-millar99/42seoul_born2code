#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
    (void) ref;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
    (void) ref;
    return *this;
}

void ScalarConverter::convert(const std::string &typeName)
{
    std::cout << "char: ";
    CharConverter::checkCharType(typeName) ? std::cout << "yes\n" : std::cout << "no\n";
    std::cout << "int: ";
    IntConverter::checkIntType(typeName) ? std::cout << "yes\n" : std::cout << "no\n";
    std::cout << "float: ";
    FloatConverter::checkFloatType(typeName) ? std::cout << "yes\n" : std::cout << "no\n";
    std::cout << "double: ";
    DoubleConverter::checkDoubleType(typeName) ? std::cout << "yes\n" : std::cout << "no\n";
}
