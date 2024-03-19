#include "Zombie.hpp"


int main()
{
	Zombie zombie("Foo");
	Zombie* _zombieHorde = zombie.zombieHorde(3, "Foo's zombieHorde");

	if (!_zombieHorde)
		return 1;
	else
	{
		for (int i = 0; i < 3; i++)
			_zombieHorde[i].announce();
	}
	delete []_zombieHorde;
	return 0;
}