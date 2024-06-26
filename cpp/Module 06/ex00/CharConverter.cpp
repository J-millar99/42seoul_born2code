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

bool CharConverter::isLimit(int inum)
{
    return (inum > CHAR_MAX || inum < CHAR_MIN);
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
        ret += str[idx] - '0';
        if (isLimit(ret * sign))
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
    FloatConverter::printFloat(static_cast<float>(ch));
    DoubleConverter::printDouble(static_cast<double>(ch));
}

void CharConverter::printChar(char ch)
{
    if (ch == 0 || ch < 9 || (13 < ch && ch < 32) || ch == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << ch << "\'" << std::endl;
}