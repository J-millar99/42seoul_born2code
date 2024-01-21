#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Constructor: Animal" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	type = ref.type;
	std::cout << "Constructor: Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &ref)
{
	if (this == &ref)
		return *this;
	type = ref.type;
	std::cout << "Constructor: Animal" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor: Animal" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal: (onomatopoeia)" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}