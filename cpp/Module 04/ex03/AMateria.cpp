#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "";
}

AMateria::AMateria(const AMateria &ref)
{
    type = ref.type;
}

AMateria &AMateria::operator=(const AMateria &ref)
{
    if (this == &ref)
        return *this;
    type = ref.type;
    return *this;
}

AMateria::~AMateria() { }

AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << target.getName();
}