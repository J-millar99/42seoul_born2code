#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* _zombieHorde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		_zombieHorde[i].name = name;
	return _zombieHorde;
}