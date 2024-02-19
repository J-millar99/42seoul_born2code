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

bool singularDot(const std::string &str)
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