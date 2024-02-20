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
        static bool outOfCharType(long long llnum);
        static bool isPrintableChar(char ch);
        static void printChar(char ch);
};

#endif