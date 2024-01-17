#include "Cat.hpp"

Cat::Cat()
{
	_brain = new Brain();
	type = "Cat";
	std::cout << "Constructor: Cat in ";
	std::cout << this << std::endl;
}

Cat::Cat(const Cat &ref)
{
	_brain = new Brain();
	type = ref.type;
	copyStringArray(ref._brain->getIdeas(), _brain->getIdeas(), 100);
	std::cout << "Constructor: Cat in ";
	std::cout << this << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
	_brain = new Brain();
	type = ref.type;
	copyStringArray(ref._brain->getIdeas(), _brain->getIdeas(), 100);
	std::cout << "Constructor: Cat in ";
	std::cout << this << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Destructor: Cat in ";
	std::cout << this << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat: miaou in " << std::endl;
	std::cout << this << std::endl;
}

std::string Cat::getType() const
{
	return type;
}