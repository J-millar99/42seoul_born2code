#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "Constructor: WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref)
{
	type = ref.type;
	std::cout << "Constructor: WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &ref)
{
	type = ref.type;
	std::cout << "Constructor: WrongCat" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor: WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: miaou" << std::endl;
}

std::string WrongCat::getType() const
{
	return type;
}