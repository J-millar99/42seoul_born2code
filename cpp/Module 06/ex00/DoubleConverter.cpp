#include "DoubleConverter.hpp"
DoubleConverter::DoubleConverter(){}
DoubleConverter::~DoubleConverter(){}
DoubleConverter::DoubleConverter(const DoubleConverter &ref)
{
    (void) ref;
}
DoubleConverter &DoubleConverter::operator=(const DoubleConverter &ref)
{
    (void) ref;
    return *this;
}

bool DoubleConverter::isDoubleType(const std::string &str)
{
    size_t idx = 0;

    if (pluralDot(str) || !haveDot(str) || !haveDigit(str))
        return false;
    if (isSign(str[idx]))
    {
        ++idx;
        if (isChar(str[idx], '.'))
            ++idx;
    }
    while (isdigit(str[idx]))
        ++idx;
    if (isChar(str[idx], '.'))
        ++idx;
    while (isdigit(str[idx]))
        ++idx;
    if (str[idx] == 0)
        return true;
    return false;
}

bool DoubleConverter::isLimit(double ret, int sign)
{
    if (sign == 1)
    {
        if (ret > DBL_MAX)
            return true;
    }
    else
    {
        if (ret > -DBL_MIN)
            return true;
    }
    return false;
}

bool DoubleConverter::isDoubleLimit(const std::string &str)
{
    double ret = 0.0;
    double fraction = 0.1;
    int sign = 1;
    size_t idx = 0;

    if (!printablePrecision(str, 16))
        return true;
    if (isSign(str[idx]))
    {
        if (str[idx] == '-')
            sign = -1;
        ++idx;
    }

    while (isdigit(str[idx]))
    {
        ret *= 10.0;
        if (isLimit(ret, sign))
            return true;
        ret += (str[idx] - '0');
        if (isLimit(ret, sign))
            return true;
        ++idx;
    }

    if (str[idx] == '.')
    {
        ++idx;
        while (isdigit(str[idx]))
        {
            ret += ((str[idx] - '0') * fraction);
            if (isLimit(ret, sign))
                return true;
            fraction *= 0.1;
            ++idx;
        }
    }
    return false;
}

void DoubleConverter::typeOfCastingFromDouble(const std::string &type)
{
    double dnum;

    std::istringstream iss(type);
    iss >> dnum;

    if (CharConverter::isCharLimit(type))
        std::cout << "char: impossible" << std::endl;
    else
        CharConverter::printChar(static_cast<char>(dnum));

    if (IntConverter::isIntLimit(type))
        std::cout << "int: impossible" << std::endl;
    else
        IntConverter::printInt(static_cast<int>(dnum));

    if (FloatConverter::isFloatLimit(type))
        std::cout << "float: impossible" << std::endl;
    else
        FloatConverter::printFloat(static_cast<float>(dnum));
    if (DoubleConverter::isDoubleLimit(type))
        std::cout << "double: impossible" << std::endl;
    else
        DoubleConverter::printDouble(dnum);
}

void DoubleConverter::printDouble(double dnum)
{
    std::cout << "double: " << dnum;
    if (std::fmod(dnum, 1.0) == 0.0)
        std::cout << ".0";
    std::cout << "\n";
}