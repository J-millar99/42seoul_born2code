#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Constructor: Cat" << std::endl;
}

Cat::Cat(const Cat &ref)
{
	type = ref.type;
	std::cout << "Constructor: Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
	type = ref.type;
	std::cout << "Constructor: Cat" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destructor: Cat" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat: miaou" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}