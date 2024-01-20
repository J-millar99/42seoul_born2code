#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &ref);
        MateriaSource &operator=(const MateriaSource &ref);
        ~MateriaSource();
        void learnMateria(AMateria *) = 0;
        AMateria *createMateria(std::string const &type) = 0;
};

#endif