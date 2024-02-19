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
        static bool checkIntType(const std::string &str);
};

#endif