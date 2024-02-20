#ifndef INTCONVERTER_HPP
#define INTCONVERTER_HPP

#include "Converter.hpp"

class IntConverter
{
    private:
        IntConverter();
        IntConverter(const IntConverter &ref);
        IntConverter &operator=(const IntConverter &ref);

    public:
        ~IntConverter();
        static bool isIntType(const std::string &str);
        static void typeOfCastingFromInt(const std::string &type);
        static bool outOfIntType(long long llnum);
        static void printInt(int inum);
};

#endif