#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "Constructor: WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	type = ref.type;
	std::cout << "Constructor: WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref)
{
	if (this == &ref)
		return *this;
	type = ref.type;
	std::cout << "Constructor: WrongAnimal" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor: WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: (onomatopoeia)" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}