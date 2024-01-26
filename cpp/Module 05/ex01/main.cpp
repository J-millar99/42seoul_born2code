#include "Bureaucrat.hpp"

int main()
{
       std::cout << "-----constructor error-----" << std::endl;
    try
    {
        Form tmp1("High Form", 1, 1);
        std::cout << tmp1;
        Form tmp2("Low Form", 150, 150);
        std::cout << tmp2;
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----sign error-----" << std::endl;
    try
    {
        Bureaucrat highB("highB", 49);
        Bureaucrat lowB("lowB", 51);
        Form tmp("High Form", 50, 50);
        tmp.beSigned(highB);
        tmp.beSigned(highB); // already signed
        tmp.beSigned(lowB); // low grade exception
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}