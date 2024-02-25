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

bool CharConverter::isCharType(const std::string &str)
{
    if (str.length() > 1 || haveDigit(str))
        return false;
    return true;
}

bool CharConverter::isLimit(int ret, int sign)
{
    if (sign == 1)
    {
        if ((ret >= CHAR_MAX / 10) && ((ret % 10) > (CHAR_MAX % 10)))
            return true;
    }
    else
    {
        if ((ret >= CHAR_MAX / 10) && ((ret % 10) > (CHAR_MAX % 10) + 1))
            return true;
    }
    return false;
}

bool CharConverter::isCharLimit(const std::string &str)
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

void CharConverter::typeOfCastingFromChar(const std::string &type)
{
    char ch = static_cast<char>(type[0]);
    CharConverter::printChar(ch);
    IntConverter::printInt(static_cast<int>(ch));
    FloatConverter::printFloat(static_cast<int>(ch));
    DoubleConverter::printDouble(static_cast<int>(ch));
}

void CharConverter::printChar(char ch)
{
    if (ch == 0 || ch < 9 || (13 < ch && ch < 32) || ch == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << ch << "\'" << std::endl;
}