#ifndef CHARCONVERTER_HPP
#define CHARCONVERTER_HPP

#include "Converter.hpp"

class CharConverter
{
    private:
        CharConverter();
        CharConverter(const CharConverter &ref);
        CharConverter &operator=(const CharConverter &ref);

    public:
        ~CharConverter();
        static bool isCharType(const std::string &str);
        static void typeOfCastingFromChar(const std::string &type);
        static void printCharOverflow();
        static void printChar(char ch);
        static bool isLimit(int ret, int sign);
        static bool isCharLimit(const std::string &str);
};

#endif