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

    if (pluralDot(str) || !singularDot(str) || !haveDigit(str))
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

void FloatConverter::typeOfCastingFromFloat(const std::string &type)
{
    std::istringstream iss(type);
    double dnum;

    iss >> dnum;
    if (!CharConverter::outOfCharType(dnum))
        CharConverter::printChar(static_cast<char>(dnum));
    if (!IntConverter::outOfIntType(dnum))
        IntConverter::printInt(static_cast<int>(dnum));
    FloatConverter::printFloat(static_cast<float>(dnum));
    DoubleConverter::printDouble(static_cast<double>(dnum));
}


void FloatConverter::printFloat(float fnum)
{
    std::cout << "float: " << fnum;
    if (std::fmod(fnum, 1.0) == 0.0)
        std::cout << ".0";
    std::cout << "f\n";
}