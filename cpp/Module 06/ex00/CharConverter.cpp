#include "CharConverter.hpp"
CharConverter::CharConverter(){}
CharConverter::~CharConverter(){}
CharConverter::CharConverter(const CharConverter &ref)
{
    (void) ref;
}
CharConverter &CharConverter::operator=(const CharConverter &ref)
{
    (void) ref;
    return *this;
}

bool CharConverter::checkCharType(const std::string &str)
{
    if (str.length() > 1 || haveDigit(str))
        return false;
    return true;
}