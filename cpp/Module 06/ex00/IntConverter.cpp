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

    if (singularDot(str) || !haveDigit(str))
        return false;
    if (str[idx] == '+' || str[idx] == '-')
        ++idx;
    while (isdigit(str[idx]))
        ++idx;
    if (str[idx])
        return false;
    return true;
}

bool IntConverter::outOfIntType(long long llnum)
{
    if (llnum > INT_MAX || llnum < INT_MIN)
    {
        std::cout << "int: Overflow" << std::endl;
        return true;
    }
    return false;
}

void IntConverter::typeOfCastingFromInt(const std::string &type)
{
    std::istringstream iss(type);
    long long llnum;

    iss >> llnum;
    if (!CharConverter::outOfCharType(llnum))
        CharConverter::printChar(static_cast<char>(llnum));
    if (!IntConverter::outOfIntType(llnum))
        IntConverter::printInt(static_cast<int>(llnum));
    FloatConverter::printFloat(static_cast<float>(llnum));
    DoubleConverter::printDouble(static_cast<double>(llnum));
}

void IntConverter::printInt(int inum)
{
    std::cout << "int: " << inum << std::endl;
}