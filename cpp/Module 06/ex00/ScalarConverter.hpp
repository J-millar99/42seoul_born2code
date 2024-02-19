#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Converter.hpp"
#include "CharConverter.hpp"
#include "IntConverter.hpp"
#include "FloatConverter.hpp"
#include "DoubleConverter.hpp"


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &ref);
        ScalarConverter &operator=(const ScalarConverter &ref);

    public:
        ~ScalarConverter();
        static void convert(const std::string &typeName);
};

#endif