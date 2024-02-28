#include "whatever.hpp"

int main()
{
    char ch1 = 'F', ch2 = 'S';
    ::func(ch1, ch2);
    int inum1 = 1, inum2 = 2;
    ::func(inum1, inum2);
    float fnum1 = 1.23, fnum2 = 4.56;
    ::func(fnum1, fnum2);
    double dnum1 = 0.1234, dnum2 = 5.789;
    ::func(dnum1, dnum2);

    // must support all the comparison operators.
    // int num1 = 1;
    // int num2 = 2;
    // int *a = &num1;
    // int *b = &num2;
    // a + b
    // must have the same type
    // ::func(ch1, dnum2);

    std::string str1 = "string1";
    std::string str2 = "string2";
    ::func(str1, str2);
    return 0;
}