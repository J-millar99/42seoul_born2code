#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t length, Func func)
{
    for (size_t idx = 0; idx < length; ++idx)
        func(array[idx]);
}

template <typename T>
void printElement(const T &element)
{
    std::cout << element << " ";
}

#endif