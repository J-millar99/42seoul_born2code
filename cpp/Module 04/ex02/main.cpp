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
	// const Animal *j = new Dog();
	// const Animal *i = new Cat();
	// delete j; // should not create a leak delete i;
	// delete i;

	/*	Constructor / Destructor */
	// Animal *animalArray[4];
	// std::cout << "@@@@@Dog Constructor@@@@@" << std::endl;
	// for (int i = 0; i < 2; i++)
	// {
	// 	Dog *dog = new Dog();
	// 	animalArray[i] = dog;
	// }
	// std::cout << std::endl << std::endl;
	// std::cout << "@@@@@Cat Constructor@@@@@" << std::endl;
	// for (int j = 2; j < 4; j++)
	// {
	// 	Cat *cat = new Cat();
	// 	animalArray[j] = cat;
	// }
	// std::cout << std::endl << std::endl;
	// std::cout << "@@@@@Animal destructor@@@@@" << std::endl;
	// for (int k = 0; k < 4; k++)
	// 	delete animalArray[k];

	/*	shallow / deep	*/
	// Dog *dog = new Dog();
	// Dog d1(*dog);

	// std::cout << dog->getType() + ": ";
	// ptrHeldAddr(dog->getBrainPtr());
	// std::cout << d1.getType() + ": ";
	// ptrHeldAddr(d1.getBrainPtr());
	// delete dog;
	return 0;
}