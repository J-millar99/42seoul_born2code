#include "Zombie.hpp"

// void f()
// {
// 	system("leaks zombie");
// }

int main()
{
	// atexit(f);
	Zombie zombie1("Foo");

	zombie1.announce();
	zombie1.randomChump("zombie2");
	Zombie *zombie3 = zombie1.newZombie("zombie3");
	zombie3->announce();
	delete zombie3;
	// exit(0);
	return 0;
}