#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arraySize(0)
{
    elements = new T[size()];
}

template <typename T>
Array<T>::Array(const Array &other) : arraySize(other.arraySize) 
{
    elements = new T[size()];

    for (unsigned int i = 0; i < size(); ++i)
        elements[i] = other.elements[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) 
{
    if (this != &other) 
    {
        delete[] elements;
        arraySize = other.size();
        elements = new T[size()];
        for (unsigned int i = 0; i < size(); ++i)
            elements[i] = other.elements[i];
    }
    return *this;
}

template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n) 
{
    elements = new T[size()];
    for (unsigned int i = 0; i < size(); ++i)
        elements[i] = T();
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) const
{
    if (!size() || index >= size())
        throw std::out_of_range("Index out of bounds");
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return arraySize;
}

template <typename T>
void Array<T>::iter() const
{
    for (size_t idx = 0; idx < size(); ++idx)
        printElement(elements[idx]);
    std::cout << std::endl;
}

template <typename T>
void Array<T>::printElement(const T &element) const
{
    std::cout << element << " ";
}

template <typename T>
void Array<T>::printArray(std::string arrayName) const
{
    std::cout << arrayName + " > ";
    this->iter();
}

#endif
