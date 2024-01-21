#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void f()
// {
// 	system("leaks a.out");
// }

int main()
{
	// atexit(f);
	// Animal test0; //compile error: abstract class is not instantiable
	const Animal *i = new Cat();
	const Animal *j = new Dog();

	i->makeSound();
	j->makeSound();
	delete i;
	delete j;
	return 0;
}