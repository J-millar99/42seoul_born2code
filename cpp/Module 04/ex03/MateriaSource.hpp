#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *memory[4];
        std::string letter[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &ref);
        MateriaSource &operator=(const MateriaSource &ref);
        ~MateriaSource();
        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);

        void inventorySet();
        void inventoryClear();
        void inventoryCopy(AMateria* const *src);
};

#endif