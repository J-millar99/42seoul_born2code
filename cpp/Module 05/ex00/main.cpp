#include "Bureaucrat.hpp"

int main()
{
    std::cout << "-----constructor error-----" << std::endl;
    try
    {
        Bureaucrat tmp1("Highest", 0);
        std::cout << tmp1; // high grade exception
        Bureaucrat tmp2("Lowest", 151);
        std::cout << tmp2; // low grade exception
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    // std::cout << "-----increase / decrease error-----" << std::endl;
    // try
    // {
    //     Bureaucrat tmp1("Highest", 1);
    //     for (; ;)
    //     {
    //         std::cout << tmp1.getGrade() << std::endl;
    //         tmp1.increaseGrade();
    //     }
    //     Bureaucrat tmp2("Lowest", 150);
    //     for (; ;)
    //     {
    //         std::cout << tmp2.getGrade() << std::endl;
    //         tmp2.decreaseGrade();
    //     }
    // }
    // catch(std::exception & e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    return 0;
}
