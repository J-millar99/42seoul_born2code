#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>

class BitcoinExchange
{
    private:
        std::map<std::string, float> database;
        BitcoinExchange(const BitcoinExchange &ref);
        BitcoinExchange &operator=(const BitcoinExchange &ref);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        int ft_atoi(const std::string &str);
        static void processError(const std::string &errorStr);
        bool isLeapYear(int year);

        void setDB();
        void inputDB(std::string fileName);
        bool checkDayValidity(int year, int month, int day);
        bool checkKeyValidity(std::string &keyStr);
        bool checkValueValidity(const std::string &valueStr);
        void calcRate(const std::string &dataKey, const std::string &dataValue);
};

#endif