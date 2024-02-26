#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
class Span
{

    private:
        int *data;
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
};

#endif