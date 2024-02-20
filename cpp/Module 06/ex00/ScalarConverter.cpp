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

void ScalarConverter::convert(const std::string &typeName)
{
    std::string type = typeName;
    if (!typeName.empty())
    {
        if (typeName[typeName.length() - 1] == 'f')
            type[typeName.length() - 1] = '\0';
        if (typeName.length() > 1 && typeName[0] == '.')
            type = "0" + type;
    }
    if (!pseudoLiterals(typeName))
    {
        if (CharConverter::isCharType(type))
            CharConverter::typeOfCastingFromChar(type);
        if (outOfLongLongType(type))
            std::cerr << "Type Range Error" << std::endl;
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
