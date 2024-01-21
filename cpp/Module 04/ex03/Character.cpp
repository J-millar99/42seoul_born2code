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
    if (idx == 4)
        return ;
    inventory[idx] = m;
    slot[idx] = 1;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
        return ;
    // 메모리 해제를 위해서, 버릴 무기를 어딘가 옮겨놓아야 함.
    inventory[idx] = NULL;
    slot[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || inventory[idx] == nullptr)
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
            if (src[i]->getType() == "ice")
                inventory[i] = new Ice();
            else if (src[i]->getType() == "cure")
                inventory[i] = new Cure();
        }
    }
    //slot개수 다시 세야함
}