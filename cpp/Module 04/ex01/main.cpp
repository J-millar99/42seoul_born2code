#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void f()
{
	system("leaks a.out");
}

void ptrHeldAddr(Brain *ptr)
{
	std::cout << ptr << std::endl;
}

int main()
{
	atexit(f);

	/*	leaks	*/
	// const Animal *i = new Dog();
	// const Animal *j = new Cat();
	// delete i; // should not create a leak delete i;
	// delete j;

	/*	Constructor / Destructor */
	// Animal *animalArray[4];
	// std::cout << "------Dog Constructor------" << std::endl;
	// for (int i = 0; i < 2; i++)
	// {
	// 	Dog *dog = new Dog();
	// 	animalArray[i] = dog;
	// }
	// std::cout << std::endl;
	// std::cout << "------Cat Constructor------" << std::endl;
	// for (int j = 2; j < 4; j++)
	// {
	// 	Cat *cat = new Cat();
	// 	animalArray[j] = cat;
	// }
	// std::cout << std::endl;
	// std::cout << "------Animal destructor------" << std::endl;
	// for (int k = 0; k < 4; k++)
	// 	delete animalArray[k];

	/*	shallow / deep	*/
	Dog *d1 = new Dog();
	Dog d2(*d1);
	Dog d3 = d2;
	Dog d4;
	d4 = d3;

	std::cout << std::endl;

	std::cout << d1->getType() + ": ";
	ptrHeldAddr(d1->getBrainPtr());
	std::cout << d2.getType() + ": ";
	ptrHeldAddr(d2.getBrainPtr());
	std::cout << d3.getType() + ": ";
	ptrHeldAddr(d3.getBrainPtr());
	std::cout << d4.getType() + ": ";
	ptrHeldAddr(d4.getBrainPtr());

	std::cout << std::endl;

	delete d1;
	return 0;
}