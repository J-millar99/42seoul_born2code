#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie _newZombie(name);

	_newZombie.announce();
}