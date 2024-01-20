#include "Ice.hpp"

Ice::Ice()
{
    type = "ice";
}


Ice::Ice(const Ice &ref)
{
    type = ref.type;
}

Ice &Ice::operator=(const Ice &ref)
{
    type = ref.type;
    return (*this);
}

Ice::~Ice() { }

AMateria *Ice::clone() const
{
    Ice *ret = new Ice();

    return ret;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at ";
    std::cout << target.getName();
    std::cout << " *" << std::endl;
}