#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
    (void) ref;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
    (void) ref;
    return *this;
}

void ScalarConverter::convert(const std::string &type)
{
    if (!pseudoLiterals(type))
    {
        if (CharConverter::isCharType(type))
            CharConverter::typeOfCastingFromChar(type);
        else if (IntConverter::isIntType(type))
            IntConverter::typeOfCastingFromInt(type);
        else if (FloatConverter::isFloatType(type))
            FloatConverter::typeOfCastingFromFloat(type);
        else if (DoubleConverter::isDoubleType(type))
            DoubleConverter::typeOfCastingFromDouble(type);
        else
            std::cerr << "Argument Error" << std::endl;
    }
}
