#include "ScavTrap.hpp"

int main()
{
    ScavTrap robot1;
    ScavTrap robot2("tester");
    ScavTrap robot3(robot2);

    robot1.guardGate();

    robot2.attack("vice");
    robot2.beRepaired(1);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
    robot2.takeDamage(15);
}