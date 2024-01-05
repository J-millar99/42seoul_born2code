#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::attack()
{
	std::cout << name
			  << " attacks with their ";
	if ((*weapon).getType() == "\0")
		std::cout << "bare hands"
				  << std::endl;
	else
		std::cout << (*weapon).getType()
				  << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}