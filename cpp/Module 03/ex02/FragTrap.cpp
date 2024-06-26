#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap: " + name + " is running" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref.getName(), 100, 100, 30)
{
    std::cout << "FragTrap: " + getName() + " is running" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: " + getName() + " is destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref)
{
    if (this == &ref)
        return (*this);
    setName(ref.getName());
    setAttack(ref.getAttack());
    setEnergy(ref.getEnergy());
    setHealth(ref.getHealth());
    std::cout << "FragTrap: " + getName() + " is running" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "1. one: ?" << std::endl
              << "2. two: ?" << std::endl
              << "3. three: ?" << std::endl
              << "4. four: ?" << std::endl
              << "5. five: ?" << std::endl << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (!getEnergy() || !getHealth())
    {
        std::cout << "FragTrap: " + getName()
                  << " can't operate" << std::endl << std::endl;
        return ;
    }
    setEnergy(getEnergy() - 1);
    std::cout << getName() + " attacks "
              << target + ", causing "
              << getAttack()
              << " points of damage!" << std::endl << std::endl;
}