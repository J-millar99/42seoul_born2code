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
        static bool checkCharType(const std::string &str);
};

#endif