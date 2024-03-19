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

unsigned int Span::shortestSpan()
{
    unsigned int intSpan = UINT_MAX;
    try
    {
        if (currentSize < 2)
            throw "no span can be found";
        std::sort(data.begin(), data.end());
        for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
            if (it + 1 != data.end())
                intSpan > static_cast<long>(*(it + 1)) - static_cast<long>(*it) ? \
                intSpan = static_cast<long>(*(it + 1)) - static_cast<long>(*it) : 0;
    }
    catch (const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        exit(1);
    }
    return intSpan; 
}

unsigned int Span::longestSpan()
{
    try
    {
        if (currentSize < 2)
            throw "no span can be found";
        std::sort(data.begin(), data.end());
        return data.back() - data.front();
    }
    catch (const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        exit(1);
    }
    return 0;
}

void Span::printContainerElements()
{
    if (currentSize == 0)
        return ;
    for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

int Span::RandomGenerator::operator()() const
{
    srand(time(0));
    return rand();
}

void Span::putNumber(unsigned int num)
{
    std::set<int> unique_values;
    std::srand(std::time(0));

    while (unique_values.size() < num)
    {
        int random_value = std::rand();
        unique_values.insert(random_value);
    }
    data.assign(unique_values.begin(), unique_values.end());
    currentSize = num;
}
