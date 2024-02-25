#include "FloatConverter.hpp"
FloatConverter::FloatConverter(){}
FloatConverter::~FloatConverter(){}
FloatConverter::FloatConverter(const FloatConverter &ref)
{
    (void) ref;
}
FloatConverter &FloatConverter::operator=(const FloatConverter &ref)
{
    (void) ref;
    return *this;
}

bool FloatConverter::isFloatType(const std::string &str)
{
    size_t idx = 0;

    if (pluralDot(str) || !haveDigit(str))
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
    if (isChar(str[idx], 'f'))
        if (str[idx + 1] == 0)
            return true;
    return false;
}

bool FloatConverter::isLimit(double ret, int sign)
{
    if (sign == 1)
    {
        if (ret > FLT_MAX)
            return true;
    }
    else
    {
        if (ret > -FLT_MIN)
            return true;
    }
    return false;
}

bool FloatConverter::isFloatLimit(const std::string &str)
{
    double ret = 0.0;
    double fraction = 0.1;
    int sign = 1;
    size_t idx = 0;

    if (!printablePrecision(str, 8))
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

void FloatConverter::typeOfCastingFromFloat(const std::string &type)
{
    float fnum;
    std::string str = type;

    str[str.length() - 1] = '\0';
    std::istringstream iss(str);
    iss >> fnum;

    if (CharConverter::isCharLimit(str))
        std::cout << "char: impossible" << std::endl;
    else
        CharConverter::printChar(static_cast<char>(fnum));

    if (IntConverter::isIntLimit(str))
        std::cout << "int: impossible" << std::endl;
    else
        IntConverter::printInt(static_cast<int>(fnum));

    if (FloatConverter::isFloatLimit(str))
        std::cout << "float: impossible" << std::endl;
    else
        FloatConverter::printFloat(fnum);
    if (DoubleConverter::isDoubleLimit(str))
        std::cout << "double: impossible" << std::endl;
    else
        DoubleConverter::printDouble(static_cast<double>(fnum));
}


void FloatConverter::printFloat(float fnum)
{
    std::cout << "float: " << fnum;
    if (std::fmod(fnum, 1.0) == 0.0)
        std::cout << ".0";
    std::cout << "f\n";
}