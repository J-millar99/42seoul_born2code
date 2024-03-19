#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
    protected:
        AMateria();
        AMateria &operator=(const AMateria &ref);
        AMateria(const AMateria &ref);
        std::string type;

    public:
        virtual ~AMateria();
        AMateria(std::string const &type);

        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif