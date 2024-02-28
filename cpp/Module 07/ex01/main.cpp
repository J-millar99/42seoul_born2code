#include "iter.hpp"

int main()
{
    std::cout << std::endl << "--Array of Char Type--" << std::endl;
    char charArr[] = {'a', 'b', 'c', 'd'};
    iter(charArr, sizeof(charArr) / sizeof(char), printElement<char>);
    std::cout << std::endl;

    std::cout << "--Array of Int Type--" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, sizeof(intArr) / sizeof(int), printElement<int>);
    std::cout << std::endl;

    std::cout << "--Array of Float Type--" << std::endl;
    float floatArr[] = {0.1f, 0.2f, 0.3f, 0.4f};
    iter(floatArr, sizeof(floatArr) / sizeof(float), printElement<float>);
    std::cout << std::endl;
    
    std::cout << "--Array of Double Type--" << std::endl;
    double doubleArr[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    iter(doubleArr, sizeof(doubleArr) / sizeof(double), printElement<double>);
    std::cout << std::endl;

    std::cout << "--Array of String Type--" << std::endl;
    std::string stringArr[] = {"Hello", "World", "!"};
    iter(stringArr, sizeof(stringArr) / sizeof(std::string), printElement<std::string>);
    std::cout << std::endl;
    return 0;
}