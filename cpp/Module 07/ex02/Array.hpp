#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int length;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &ref);
        Array &operator=(const Array &ref);
        ~Array();
        unsigned int getLength() const;
        T &operator[](unsigned int idx);
        #include "Array.tpp"
};

#endif
