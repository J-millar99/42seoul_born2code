#include "IntConverter.hpp"
IntConverter::IntConverter(){}
IntConverter::~IntConverter(){}
IntConverter::IntConverter(const IntConverter &ref)
{
    (void) ref;
}
IntConverter &IntConverter::operator=(const IntConverter &ref)
{
    (void) ref;
    return *this;
}

bool IntConverter::isIntType(const std::string &str)
{
    size_t idx = 0;

    if (haveDot(str) || !haveDigit(str))
        return false;
    if (isSign(str[idx]))
        ++idx;
    while (isdigit(str[idx]))
        ++idx;
    if (str[idx])
        return false;
    return true;
}

bool IntConverter::isLimit(long lnum)
{
    return (lnum > INT_MAX || lnum < INT_MIN);
}

bool IntConverter::isIntLimit(const std::string &str)
{
    size_t idx = 0;
    int sign = 1;
    long ret = 0;

    if (isSign(str[idx]))
    {
        if (str[idx] == '-')
            sign = -1;
        ++idx;
    }
    while (isdigit(str[idx]))
    {
        ret *= 10;
        ret += str[idx] - '0';
        if (isLimit(ret * sign))
            return true;
        ++idx;
    }
    return false;
}

void IntConverter::typeOfCastingFromInt(const std::string &type)
{
    int inum;

    std::istringstream iss(type);
    iss >> inum;

    if (CharConverter::isCharLimit(type))
        std::cout << "char: impossible" << std::endl;
    else
        CharConverter::printChar(static_cast<char>(inum));

    if (IntConverter::isIntLimit(type))
        std::cout << "int: impossible" << std::endl;
    else
        IntConverter::printInt(inum);

    if (FloatConverter::isFloatLimit(type))
        std::cout << "float: impossible" << std::endl;
    else
        FloatConverter::printFloat(static_cast<float>(inum));
    if (DoubleConverter::isDoubleLimit(type))
        std::cout << "double: impossible" << std::endl;
    else
        DoubleConverter::printDouble(static_cast<double>(inum));
}

void IntConverter::printInt(int inum)
{
    std::cout << "int: " << inum << std::endl;
}