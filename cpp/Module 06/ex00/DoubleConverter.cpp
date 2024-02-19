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

bool DoubleConverter::checkDoubleType(const std::string &str)
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