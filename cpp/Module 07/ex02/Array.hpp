#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int arraySize;

    public:
        Array();
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        Array(unsigned int n);
        T &operator[](unsigned int index) const;
        unsigned int size() const;
        void iter() const;
        void printElement(const T &element) const;
        void printArray(std::string arrayName) const;
};
#include "Array.tpp"

#endif
