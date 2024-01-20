#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	setName(name + "_clap_name");
    setHealth(FT_HEALTH);
    setEnergy(ST_ENERGY);
    setAttack(FT_ATTACK);
	std::cout << "DiamondTrap: " + name + " is running" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref)
{
	name = ref.name;
    setName(ref.getName());
    setAttack(ref.getAttack());
    setEnergy(ref.getEnergy());
    setHealth(ref.getHealth());
	std::cout << "DiamondTrap: " + name + " is running" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: " + name + " is destroyed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
    if (this == &ref)
        return (*this);
    setName(ref.getName());
    setAttack(ref.getAttack());
    setEnergy(ref.getEnergy());
    setHealth(ref.getHealth());
    std::cout << "DiamondTrap: " + name + " is running" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "name of DiamondTrap: " << name << std::endl;
	std::cout << "name of ClapTrap: " << getName() << std::endl;
}
