#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Constructor: Animal in ";
	std::cout << this << std::endl;
}

Animal::Animal(const Animal &ref)
{
	type = ref.type;
	std::cout << "Constructor: Animal in ";
	std::cout << this << std::endl;
}

Animal &Animal::operator=(const Animal &ref)
{
	type = ref.type;
	std::cout << "Constructor: Animal in ";
	std::cout << this << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor: Animal in ";
	std::cout << this << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal: (onomatopoeia) in ";
	std::cout << this << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::copyStringArray(const std::string *source, std::string *destination, int size)
{
    for (int i = 0; i < size; i++)
        destination[i] = source[i];
}