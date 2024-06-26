#include "Converter.hpp"

bool pluralDot(const std::string &str)
{
    int cnt = 0;
    int idx = 0;

    while (str[idx])
    {
        if (str[idx] == '.')
            ++cnt;
        ++idx;
    }
    if (cnt > 1)
        return true;
    return false;
}

bool haveDot(const std::string &str)
{
    int idx = 0;

    while (str[idx])
    {
        if (str[idx] == '.')
            return true;
        ++idx;
    }
    return false;
}

bool isSign(const char &ch)
{
    if (ch && (ch == '+' || ch == '-'))
        return true;
    return false;
}

bool isNegativeSign(const char &ch)
{
    if (ch == '-')
        return true;
    return false;
}

bool isChar(const char &ch1, const char &ch2)
{
    if (ch1 && ch2 && (ch1 == ch2))
        return true;
    return false;
}

bool haveDigit(const std::string &str)
{
    int idx = 0;

    while (str[idx])
    {
        if (isdigit(str[idx]))
            return true;
        ++idx;
    }
    return false;
}

bool printablePrecision(const std::string &str, size_t digit)
{
    size_t dotIndex = str.find_last_of('.');
    if (dotIndex != std::string::npos)
    {
        size_t lengthAfterDot = str.length() - dotIndex - 1;
        return lengthAfterDot < digit + 1 ? true : false;
    }
    return true;
}

void argumentEmpty(const std::string &str)
{
    char ch = static_cast<char>(str[0]);
    int inum = static_cast<int>(ch);
    float fnum = static_cast<float>(ch);
    double dnum = static_cast<double>(ch);

    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << inum << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << fnum << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << dnum << std::endl;
}

bool isNotANumber()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
    return true;
}

bool isInfinity()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
    return true;
}

bool isPositiveInfinity()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
    return true;
}

bool isNegativeInfinity()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
    return true;
}

bool pseudoLiterals(const std::string &str)
{
    std::string literals[8] = {"nan", "nanf", "inf", "inff", "+inf", "+inff", "-inf", "-inff"};
    size_t idx = 8;

    for (size_t i = 0; i < 8; ++i)
        literals[i] == str ? idx = i : 0;

    idx = (idx / 2) + 1;
    switch (idx)
    {
    case 1:
        return isNotANumber();
    case 2:
        return isInfinity();
    case 3:
        return isPositiveInfinity();
    case 4:
        return isNegativeInfinity();
    default:
        return false;
    }
}