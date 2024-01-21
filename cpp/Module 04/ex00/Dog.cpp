#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Constructor: Dog" << std::endl;
}

Dog::Dog(const Dog &ref)
{
	type = ref.type;
	std::cout << "Constructor: Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &ref)
{
	if (this == &ref)
		return *this;
	type = ref.type;
	std::cout << "Constructor: Dog" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor: Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog: ouaf-ouaf" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}