#include "FragTrap.hpp"

int main()
{
    FragTrap robot1;
    FragTrap robot2("tester");
    FragTrap robot3(robot2);

    robot1.highFivesGuys();

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