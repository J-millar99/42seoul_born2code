#include "Zombie.hpp"

int main()
{
	Zombie zombie1("Foo");

	zombie1.announce();
	zombie1.randomChump("zombie2");
	Zombie *zombie3 = zombie1.newZombie("zombie3");
	zombie3->announce();
	delete zombie3;
	return 0;
}