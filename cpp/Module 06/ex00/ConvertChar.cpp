#include "ScalarConverter.hpp"

bool singleDot(const std::string &str)
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
        return false;
    return true;
}

int charAtoi(const std::string &str)
{
    size_t idx = 0;
    long    num = 0;

    if (!singleDot(str))
        return -1;
    if (str[idx] == '+' || str[idx] == '-')
    {
        if (str[idx] == '-')
            return -1;
        idx++;
    }
    if (str[idx] == '.')
        return -1;
    while (isdigit(str[idx]))
    {
        num *= 10;
        num += str[idx] - '0';
        idx++;
    }
    if (str[idx] && str[idx] != '.')
        return -1;
    return num;
}

void ScalarConverter::printableChar(char &ch)
{
    if ((0 <= ch && ch <= 8) || (14 <= ch && ch <= 31) || ch == 127)
        printErrorMessage("char: Non displayble");
    else if (ch < 0)
        printErrorMessage("char: impossible");
    else
        std::cout << "char: '" << ch << '\'' << std::endl;
}

char ScalarConverter::convertChar(const std::string &str)
{
    if (str.length() <= 1 && !isdigit(str[0]))
        return static_cast<char>(str[0]);
    else
        return static_cast<char>(charAtoi(str));
}
