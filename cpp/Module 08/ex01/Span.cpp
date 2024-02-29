#include "Span.hpp"
Span::Span() {}
Span::~Span(){}
Span::Span(const Span &ref) : maxSize(ref.maxSize), currentSize(ref.currentSize)
{
    this->data = ref.data;
}
Span &Span::operator=(const Span &ref)
{
    if (this != &ref)
    {
        maxSize = ref.maxSize;
        currentSize = ref.currentSize;
        this->data = ref.data;
    }
    return *this;
}
Span::Span(unsigned int N)
{
    maxSize = N;
    currentSize = 0;
}

void Span::addNumber(int num)
{
    try
    {
        if (currentSize == maxSize)
            throw "Span is full";
        for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
            if (*it == num)
                throw "Duplication!";
        data.push_back(num);
        ++currentSize;
    }
    catch (const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        exit(1);
    }
}

unsigned int Span::shortestSpan() const
{
    unsigned int intSpan;
    try
    {
        if (currentSize < 2)
            throw "no span can be found";
        for (size_t idx = 0; idx < currentSize - 1; ++idx) {
            for (size_t jdx = idx + 1; jdx < currentSize; ++jdx) {
                long distance = static_cast<long>(data[idx]) - static_cast<long>(data[jdx]);
                    if (intSpan > std::abs(distance))
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

        int max_value = data[0];
        for (size_t i = 1; i < currentSize; ++i)
            if (data[i] > max_value)
                max_value = data[i];

        int min_value = data[0];
        for (size_t i = 1; i < currentSize; ++i)
            if (data[i] < min_value)
                min_value = data[i];
        intSpan = static_cast<unsigned int>(max_value - min_value);
    }
    catch (const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        exit(1);
    }
    return intSpan;
}

void Span::printContainerElements() const
{
    if (currentSize == 0)
        return ;
    for (size_t i = 0; i < currentSize; ++i)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

void Span::putNumber(unsigned int num)
{
    std::set<int> unique_values;
    std::srand(std::time(0));

    while (unique_values.size() < num)
    {
        int random_value = std::rand() % 10000 + 1;
        unique_values.insert(random_value);
    }
    data.assign(unique_values.begin(), unique_values.end());
    currentSize = num;
}
