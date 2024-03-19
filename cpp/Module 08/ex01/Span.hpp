#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>
#include <climits>
#include <set>

class Span
{
    private:
        std::vector<int> data;
        unsigned int maxSize;
        unsigned int currentSize;       
        Span();
        struct RandomGenerator
        {
            int operator()() const;
        };

        public : ~Span();
        Span(const Span &ref);
        Span &operator=(const Span &ref);
        Span(unsigned int N);
        void addNumber(int num);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void printContainerElements();
        void putNumber(unsigned int num);
};

#endif