#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie *_newZombie = new Zombie(name);
	return _newZombie;
}