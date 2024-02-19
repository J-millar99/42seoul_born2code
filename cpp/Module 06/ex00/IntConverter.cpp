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

bool IntConverter::checkIntType(const std::string &str)
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