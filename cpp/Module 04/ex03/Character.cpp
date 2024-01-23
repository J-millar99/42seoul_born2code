#include "Character.hpp"

Character::Character()
{
    inventorySet();
    this->name = "tester";
}

Character::Character(std::string const &name)
{
    inventorySet();
    this->name = name;
}

Character::Character(const Character &ref)
{
    std::cout << "hi\n";
    inventoryClear();
    this->name = ref.name;
    inventoryCopy(ref.inventory);
}

Character &Character::operator=(const Character &ref)
{
    if (this == &ref)
        return *this;
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
    int idx;

    for (idx = 0; idx < 4; idx++)
        if (slot[idx] == 0)
            break ;
    if (!m || idx == 4)
        return ;
    inventory[idx] = m;
    slot[idx] = 1;
}

AMateria *Character::unequipPtr(int idx)
{
    return inventory[idx];
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
        return ;
    inventory[idx] = NULL;
    slot[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
        return ;
    else
        inventory[idx]->use(target);
}

void Character::inventorySet()
{
    for (int i = 0; i < 4; i++)
    {
        slot[i] = 0;
        inventory[i] = NULL;
    }
}

void Character::inventoryClear()
{
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
    inventorySet();
}

void Character::inventoryCopy(AMateria* const *src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src[i])
        {
            inventory[i] = src[i]->clone();
            slot[i] = 1;
        }
    }
    
}