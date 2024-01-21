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
	std::cout << "-----False case-----" << std::endl;
	const WrongAnimal *a = new WrongAnimal();
	const WrongAnimal *b = new WrongCat();

	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;

	a->makeSound();
	b->makeSound();  // will output the cat sound?
	return 0;
}