#include "Character.hpp"

void Character::inventorySet()
{
    slot = 0;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;    
}

void Character::inventoryClear()
{
    slot = 0;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
        else
            return ;
    }
}

void Character::inventoryCopy(AMateria* const *src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src[i])
        {
            if (src[i]->getType() == "ice")
                inventory[i] = new Ice();
            else // src[i]->getType() == "cure"
                inventory[i] = new Cure();
            slot++;
        }
        else
            return ;
    }
}

Character::Character(std::string const &name)
{
    inventorySet();
    this->name = name;
}

Character::Character(const Character &ref)
{
    inventoryClear();
    this->name = ref.name;
    inventoryCopy(ref.inventory);
}

Character &Character::operator=(const Character &ref)
{
    inventoryClear();
    this->name = ref.name;
    inventoryCopy(ref.inventory);
    return (*this);
}

Character::~Character()
{
    inventoryClear();
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (slot == 4)
        return ;
    for (int i = 0; i < 4; i++)
        if (!inventory[i])
            inventory[i] = m;
    slot++;
}

void Character::unequip(int idx)
{

    slot--;
}

void Character::use(int idx, ICharacter &target)
{
    if (4 < idx || idx < 0)
        return ;
    if (inventory[idx])
        inventory[idx]->use(target);
}
