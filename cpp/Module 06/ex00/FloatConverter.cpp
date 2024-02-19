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

bool FloatConverter::checkFloatType(const std::string &str)
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