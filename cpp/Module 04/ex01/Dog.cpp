#include "Dog.hpp"

Dog::Dog()
{
	_brain = new Brain();
	type = "Dog";
	std::cout << "Constructor: Dog in ";
	std::cout << this << std::endl;
}

Dog::Dog(const Dog &ref)
{
	_brain = new Brain();
	type = ref.type;
	copyStringArray(ref._brain->getIdeas(), _brain->getIdeas(), 100); // deep
	// _brain = ref._brain; // shallow
	std::cout << "Constructor: Dog in ";
	std::cout << this << std::endl;
}

Dog &Dog::operator=(const Dog &ref)
{
	_brain = new Brain();
	type = ref.type;
	copyStringArray(ref._brain->getIdeas(), _brain->getIdeas(), 100);
	std::cout << "Constructor: Dog in ";
	std::cout << this << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Destructor: Dog in ";
	std::cout << this << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog: ouaf-ouaf in ";
	std::cout << this << std::endl;
}

std::string Dog::getType() const
{
	return type;
}

Brain *Dog::getBrainPtr() const
{
	return _brain;
}