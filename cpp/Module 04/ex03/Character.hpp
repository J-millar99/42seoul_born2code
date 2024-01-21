#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        int slot[4];

    public:
        Character();
        ~Character();
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
};

#endif