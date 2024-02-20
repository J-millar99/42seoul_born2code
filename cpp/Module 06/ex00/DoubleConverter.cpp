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
    if (str[idx] == 0)
        return true;
    return false;
}

void DoubleConverter::typeOfCastingFromDouble(const std::string &type)
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

void DoubleConverter::printDouble(double dnum)
{
    std::cout << "double: " << dnum;
    if (std::fmod(dnum, 1.0) == 0.0)
        std::cout << ".0";
    std::cout << "\n";
}