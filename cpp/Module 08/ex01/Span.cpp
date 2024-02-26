#include "Span.hpp"
Span::Span() {}

Span::Span(const Span &ref) : maxSize(ref.maxSize), currentSize(ref.currentSize)
{
    delete []data;
    data = new int[maxSize];
}
Span &Span::operator=(const Span &ref)
{
    if (this != &ref)
    {
        delete []data;
        maxSize = ref.maxSize;
        currentSize = ref.currentSize;
        data = new int[maxSize];
    }
    return *this;
}

Span::Span(unsigned int N)
{
    maxSize = N;
    data = new int[maxSize];
    currentSize = 0;
}

Span::~Span()
{
    delete []data;
}

void Span::addNumber(int num)
{
    try
    {
        int *findValue = std::find(data, data + maxSize, num);
        if (findValue != data + maxSize)
            throw "Duplication!";
        if (currentSize < maxSize)
            data[currentSize++] = num;
        else
            std::cerr << "Span is full" << std::endl;
    }
    catch (const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        exit(1);
    }
}

unsigned int Span::shortestSpan() const
{
    unsigned int intSpan = UINT_MAX;
    try
    {
        if (currentSize < 2)
            throw "no span can be found";
        for (unsigned int idx = 0; idx < currentSize - 1; ++idx)
        {
            for (unsigned int jdx = idx + 1; jdx < currentSize; ++jdx)
            {
                long distance = (long)data[idx] - (long)data[jdx];
                if (intSpan > distance)
                    intSpan = std::abs(distance);
            }
        }
    }
    catch (const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        exit(1);
    }
    return intSpan; 
}

unsigned int Span::longestSpan() const
{
    unsigned int intSpan;
    try
    {
        if (currentSize < 2)
            throw "no span can be found";
        int *max = std::max_element(data, data + currentSize);
        int *min = std::min_element(data, data + currentSize);
        intSpan = *max - *min;
    }
    catch (const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        exit(1);
    }
    return intSpan;
}