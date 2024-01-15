#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot1;
    ClapTrap robot2("tester");
    // ClapTrap robot3(robot2);
    // ClapTrap robot4 = robot3;

    robot1.attack("tester");
    robot1.takeDamage(0);
    robot1.attack("tester");
    robot1.beRepaired(-1);
    robot1.takeDamage(3);
}