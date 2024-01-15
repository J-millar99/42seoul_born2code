#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("dummy", 20, 50, 100)
{
    std::cout << "ScavTrap: dummy is running" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 20, 50, 100)
{
    std::cout << "ScavTrap: " + name + " is running" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref.getName(), 100, 50, 20)
{
    // setName(ref.getName());
    // setAttack(ref.getAttack());
    // setEnergy(ref.getEnergy());
    // setHealth(ref.getHealth());
    std::cout << "ScavTrap: " + getName() + " is running" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: " + getName() + " is destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref)
{
    setName(ref.getName());
    setAttack(ref.getAttack());
    setEnergy(ref.getEnergy());
    setHealth(ref.getHealth());
    std::cout << "ScavTrap: " + getName() + " is running" << std::endl;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " + getName() + " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (!getEnergy() || !getHealth())
    {
        std::cout << "ScavTrap: " + getName()
                  << " can't operate" << std::endl << std::endl;
        return ;
    }
    setEnergy(getEnergy() - 1);
    std::cout << getName() + " attacks "
              << target + ", causing "
              << getAttack()
              << " points of damage!" << std::endl << std::endl;
}