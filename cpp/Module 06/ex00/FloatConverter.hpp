#ifndef FLOATCONVERTER_HPP
#define FLOATCONVERTER_HPP

#include "Converter.hpp"

class FloatConverter
{
    private:
        FloatConverter();
        FloatConverter(const FloatConverter &ref);
        FloatConverter &operator=(const FloatConverter &ref);

    public:
        ~FloatConverter();
        static bool isFloatType(const std::string &str);
        static void typeOfCastingFromFloat(const std::string &type);
        static void printFloat(float fnum);
};

#endif