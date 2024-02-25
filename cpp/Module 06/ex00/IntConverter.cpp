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

bool IntConverter::isLimit(int ret, int sign)
{
    if (sign == 1)
    {
        if ((ret >= INT_MAX / 10) && ((ret % 10) > (INT_MAX % 10)))
            return true;
    }
    else
    {
        if ((ret >= INT_MAX / 10) && ((ret % 10) > (INT_MAX % 10) + 1))
            return true;
    }
    return false;
}

bool IntConverter::isIntLimit(const std::string &str)
{
    size_t idx = 0;
    int sign = 1;
    int ret = 0;

    if (isSign(str[idx]))
    {
        if (str[idx] == '-')
            sign = -1;
        ++idx;
    }
    while (isdigit(str[idx]))
    {
        ret *= 10;
        if (isLimit(ret, sign))
            return true;
        ret += str[idx] - '0';
        if (isLimit(ret, sign))
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
    DoubleConverter::printDouble(static_cast<double>(inum));
}

void IntConverter::printInt(int inum)
{
    std::cout << "int: " << inum << std::endl;
}