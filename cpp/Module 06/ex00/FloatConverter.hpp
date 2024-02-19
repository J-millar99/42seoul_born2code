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
        static bool checkFloatType(const std::string &str);

};

#endif