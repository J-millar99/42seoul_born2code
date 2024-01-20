#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character
{
    private:
        typedef struct
        {
            AMateria *remain;
            void *next;
        } Floor;

        Floor *floor;
        int slot;
        std::string name;
        AMateria *inventory[4];
        Character();

    public:
        Character(std::string const &name);
        Character(const Character &ref);
        Character &operator=(const Character &ref);

        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);

        void inventorySet();
        void inventoryClear();
        void inventoryCopy(AMateria* const *src);

        /*  IMateriaSource   */
        void learnMateria(AMateria *src);
        AMateria *createMateria(std::string const &type);
};

#endif