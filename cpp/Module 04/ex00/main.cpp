#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-----True case-----" << std::endl;
	const Animal *meta = new Animal();
	const Animal *i = new Cat();
	const Animal *j = new Dog();
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();

	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	return 0;
	// std::cout << "-----False case-----" << std::endl;
	// const WrongAnimal *a = new WrongAnimal();
	// const WrongAnimal *b = new WrongCat();

	// std::cout << a->getType() << " " << std::endl;
	// std::cout << b->getType() << " " << std::endl;

	// a->makeSound();
	// b->makeSound();  // will output the cat sound?
	// delete a;
	// delete b;
	// return 0;
}