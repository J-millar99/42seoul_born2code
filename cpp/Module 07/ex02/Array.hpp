#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int arraySize;

    public:
        Array();
        explicit Array(unsigned int n);
        Array(const Array& other);
        Array &operator=(const Array& other);
        ~Array();
        T& operator[](unsigned int index);
        unsigned int size() const;
};

#include "Array.tpp"
#endif
