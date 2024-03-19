#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T c = a;

    a = b;
    b = c;
}

template <typename T>
T min(T a, T b)
{
    return a >= b ? b : a;
}

template <typename T>
T max(T a, T b)
{
    return a <= b ? b : a;
}

template <typename T>
void func(T a, T b)
{
    std::cout << "before > ";
    ::swap(a, b);
    std::cout << "after > ";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
}

#endif