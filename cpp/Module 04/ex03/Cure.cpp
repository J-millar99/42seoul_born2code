#include "Cure.hpp"

Cure::Cure()
{
    type = "cure";
}

Cure::Cure(const Cure &ref)
{
    type = ref.type;
}

Cure &Cure::operator=(const Cure &ref)
{
    type = ref.type;
    return (*this);
}

Cure::~Cure() { }

AMateria *Cure::clone() const
{
    Cure *ret = new Cure();

    return ret;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals ";
    std::cout << target.getName();
    std::cout << "'s wounds *" << std::endl;
}