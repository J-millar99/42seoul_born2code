#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;

	Zombie* _zombieHorde = new Zombie[N];

	if (!_zombieHorde)
		return (NULL);
	for (int i = 0; i < N; i++)
		_zombieHorde[i].name = name;
	return _zombieHorde;
}