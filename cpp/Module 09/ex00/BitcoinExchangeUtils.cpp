#include "BitcoinExchange.hpp"

int BitcoinExchange::ft_atoi(const std::string &str)
{
    long inum = 0;
    size_t idx = 0;

    if (!str[0])
        return 0;
    while (isdigit(str[idx]))
    {
        inum *= 10;
        inum += str[idx] - '0';
        if (inum > INT_MAX || inum < INT_MIN)
            return -1;
        ++idx;
    }
    if (str[idx])
        return 0;
    return static_cast<int>(inum);
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::processError(const std::string &errorStr)
{
    std::cerr << errorStr << std::endl;
    std::exit(1);
}