#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) { }

AMateria::AMateria() { }

AMateria::AMateria(const AMateria &ref) { }

AMateria &AMateria::operator=(const AMateria &ref) { }

AMateria::~AMateria() { }

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    
}