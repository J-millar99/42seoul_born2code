#include "ScavTrap.hpp"

int main()
{
    ScavTrap t1("tester1");
    ScavTrap t2(t1);
    ScavTrap t3 = t2;

    std::cout << "-----t1-----" << std::endl;
    t1.attack("dummy");
    t1.takeDamage(1);
    t1.takeDamage(1);
    t1.beRepaired(1);
    t1.guardGate();

    std::cout << "-----t2-----" << std::endl;
    t2.attack("dummy");
    t2.takeDamage(100);
    t2.takeDamage(100);
    t2.beRepaired(100);
    t2.guardGate();

    std::cout << "-----t1-----" << std::endl;
    t3.attack("dummy");
    t3.takeDamage(1000);
    t3.takeDamage(1000);
    t3.beRepaired(1000);
    t3.guardGate();

    return 0;
}