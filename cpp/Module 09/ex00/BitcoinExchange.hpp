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
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &ref);
        BitcoinExchange &operator=(const BitcoinExchange &ref);
        ~BitcoinExchange();
        int ft_atoi(const std::string &str);
        void setDB();
        void inputDB(std::string fileName);
        bool isLeapYear(int year);
        bool checkDayValidity(int year, int month, int day);
        bool checkKeyValidity(std::string &keyStr);
        bool checkValueValidity(const std::string &valueStr);
        void calcRate(const std::string &dataKey, const std::string &dataValue);
        void printfunc();
};

#endif