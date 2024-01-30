#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &ref);
        ScalarConverter &operator=(const ScalarConverter &ref);

    public:
        ~ScalarConverter();
        static void convert(const std::string &typeName);
        static char convertChar(const std::string &str);
        static int convertInt(std::string str);
        // float convertFloat(std::string str);
        // double convertDouble(std::string str);
        static void printableChar(char &ch);
        static void printableInt(int &num);
        static void printErrorMessage(const std::string &msg);
};

#endif