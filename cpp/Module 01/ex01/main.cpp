#include "Zombie.hpp"

int main()
{
	Zombie zombie("Foo");
	Zombie* _zombieHorde = zombie.zombieHorde(6, "Foo's zombieHorde");

	for (int i = 0; i < 6; i++)
		_zombieHorde[i].announce();
	delete []_zombieHorde;
	// exit(0);
	return 0;
}