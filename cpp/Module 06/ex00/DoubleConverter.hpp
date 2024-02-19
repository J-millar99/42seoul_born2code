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
        static bool checkDoubleType(const std::string &str);

};

#endif