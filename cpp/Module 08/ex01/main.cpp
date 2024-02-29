#include "Span.hpp"

int main()
{
    unsigned int num = 10000; // <<
    Span sp = Span(num);
    sp.printContainerElements();
    sp.addNumber(6);
    sp.printContainerElements();
    sp.addNumber(3);
    sp.printContainerElements();
    sp.addNumber(17);
    sp.printContainerElements();
    sp.addNumber(9);
    sp.printContainerElements();
    sp.addNumber(11);
    sp.printContainerElements();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "random number : " << num << std::endl;
    Span sp_random(num);
    sp_random.putNumber(num);
    sp_random.printContainerElements();
    std::cout << sp_random.shortestSpan() << std::endl;
    std::cout << sp_random.longestSpan() << std::endl;
    return 0;
}
