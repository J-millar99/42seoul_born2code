#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <iomanip>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        AMateria();
        AMateria(const AMateria &ref);
        AMateria &operator=(const AMateria &ref);
        std::string type;

    public:
        ~AMateria();
        AMateria(std::string const &type);

        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif