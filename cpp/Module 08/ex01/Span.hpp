#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>

class Span
{
    private:
        std::vector<int> data;
        unsigned int maxSize;
        unsigned int currentSize;       
        Span();
        
    public:
        ~Span();
        Span(const Span &ref);
        Span &operator=(const Span &ref);
        Span(unsigned int N);
        void addNumber(int num);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        void printContainerElements() const;
        void putNumber(unsigned int num);
};

#endif