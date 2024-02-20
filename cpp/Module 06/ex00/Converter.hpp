#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cfloat>
#include "ScalarConverter.hpp"

bool pluralDot(const std::string &str);
bool singularDot(const std::string &str);
bool isSign(const char &ch);
bool isNegativeSign(const char &ch);
bool isChar(const char &ch1, const char &ch2);
bool haveDigit(const std::string &str);
bool isNotANumber();
bool isPositiveInfinity();
bool isPositiveInfinity();
bool isNegativeInfinity();
bool outOfLongLongType(const std::string &type);
bool pseudoLiterals(const std::string &str);

#endif