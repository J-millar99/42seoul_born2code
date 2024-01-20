#include "DiamondTrap.hpp"

void getStatus(DiamondTrap &ref)
{
	std::cout << std::endl << "damage: " << ref.getAttack() << std::endl;
	std::cout << "energy: " << ref.getEnergy() << std::endl;
	std::cout << "hit point: " << ref.getHealth() << std::endl << std::endl;
}

int main()
{
	std::cout << "-----tester-----" << std::endl;
	DiamondTrap tester("tester");

	getStatus(tester);
	tester.attack("dummy");
	tester.takeDamage(2);
	tester.beRepaired(10);
	tester.whoAmI();
	getStatus(tester);

	std::cout << "-----clone1-----" << std::endl;
	DiamondTrap clone1(tester);
	getStatus(clone1);
	clone1.attack("dummy");
	clone1.takeDamage(100);
	clone1.beRepaired(100);
	clone1.whoAmI();
	getStatus(clone1);

	std::cout << "-----clone2-----" << std::endl;
	DiamondTrap clone2 = clone1;
	getStatus(clone2);
	clone2.attack("dummy");
	clone2.takeDamage(1000);
	clone2.beRepaired(1000);
	clone2.whoAmI();
	getStatus(clone2);
	clone2.attack("dummy");
	clone2.takeDamage(1000);
	clone2.beRepaired(1000);
}