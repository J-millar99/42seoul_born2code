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

bool CharConverter::outOfCharType(long long llnum)
{
    if (llnum > CHAR_MAX || llnum < CHAR_MIN)
    {
        std::cout << "char: Overflow" << std::endl;
        return true;
    }
    else if (isPrintableChar(static_cast<char>(llnum)))
        return false;
    return true;
}

void CharConverter::typeOfCastingFromChar(const std::string &type)
{
    char ch = static_cast<char>(type[0]);
    if (CharConverter::isPrintableChar(ch))
        CharConverter::printChar(ch);
    IntConverter::printInt(static_cast<int>(ch));
    FloatConverter::printFloat(static_cast<int>(ch));
    DoubleConverter::printDouble(static_cast<int>(ch));
}


bool CharConverter::isPrintableChar(char ch)
{
    if (ch == 0 || ch < 9 || (13 < ch && ch < 32) || ch == 127)
    {
        std::cout << "char: Non displayable" << std::endl;
        return false;
    }
    return true;
}

void CharConverter::printChar(char ch)
{
    std::cout << "char: '" << ch << "\'" << std::endl;
}