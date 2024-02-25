#ifndef DOUBLECONVERTER_HPP
#define DOUBLECONVERTER_HPP

#include "Converter.hpp"

class DoubleConverter
{
    private:
        DoubleConverter();
        DoubleConverter(const DoubleConverter &ref);
        DoubleConverter &operator=(const DoubleConverter &ref);

    public:
        ~DoubleConverter();
        static bool isDoubleType(const std::string &str);
        static void typeOfCastingFromDouble(const std::string &type);
        static void printDouble(double dnum);
        static bool isLimit(double ret, int sign);
        static bool isDoubleLimit(const std::string &str);
};

#endif