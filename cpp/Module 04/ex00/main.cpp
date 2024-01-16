#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "True case" << std::endl << std::endl;
	const Animal *meta = new Animal();
	const Animal *i = new Cat();
	const Animal *j = new Dog();
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "False case" << std::endl << std::endl;
	const WrongAnimal *x = new WrongAnimal();
	const WrongAnimal *y = new WrongCat();

	std::cout << x->getType() << " " << std::endl;
	std::cout << y->getType() << " " << std::endl;

	x->makeSound();
	y->makeSound();

	return 0;
}