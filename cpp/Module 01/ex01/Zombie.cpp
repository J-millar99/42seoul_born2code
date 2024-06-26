#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << name
		<< ": die"
		<< std::endl;
}

void Zombie::announce()
{
	std::cout << name
		<< ": "
		<< "BraiiiiiiinnnzzzZ..."
		<< std::endl;
}