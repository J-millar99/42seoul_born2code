#include "ClapTrap.hpp"

int main()
{
    // ClapTrap t;
    ClapTrap t1("tester1");
    ClapTrap t2(t1);
    ClapTrap t3 = t2;

    std::cout << "-----t1-----" << std::endl;
    t1.attack("dummy");
    t1.takeDamage(1);
    t1.takeDamage(1);
    t1.beRepaired(1);

    std::cout << "-----t2-----" << std::endl;
    t2.attack("dummy");
    t2.takeDamage(10);
    t2.takeDamage(10);
    t2.beRepaired(10);

    std::cout << "-----t1-----" << std::endl;
    t3.attack("dummy");
    t3.takeDamage(100);
    t3.takeDamage(100);
    t3.beRepaired(100);
    return 0;
}