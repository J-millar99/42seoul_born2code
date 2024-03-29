#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void f()
{
	system("leaks a.out");
}

int main()
{
	atexit(f);
	// Animal abstractClass; //compile error: abstract class is not instantiable
	const Animal *i = new Cat();
	const Animal *j = new Dog();

	std::cout << std::endl;

	i->makeSound();
	j->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;
	return 0;
}