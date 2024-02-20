#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(nullptr), length(0){}

template <typename T>
Array<T>::Array(unsigned int n)
{
    elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &ref) : length(ref.length)
{
    elements = new T[length];
    for (unsigned int idx = 0; idx < length; ++idx)
        elements[idx] = ref.elements[idx];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &ref)
{
    if (this != &ref)
    {
        delete[] elements;
        length = ref.length;
        elements = new T[length];
        for (unsigned int idx = 0; idx < length; ++idx)
            elements[idx] = ref.elements[idx];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int idx)
{
    if (idx >= length)
        throw std::out_of_range("Index out of bounds");
    return elements[idx];
}

template <typename T>
Array<T>::~Array()
{
    delete []elements;
}

template <typename T>
unsigned int Array<T>::getLength() const
{
    return length;
}