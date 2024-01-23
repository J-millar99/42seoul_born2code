#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    inventorySet();
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
    inventoryClear();
    inventoryCopy(ref.memory);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ref)
{
    if (this == &ref)
        return *this;
    inventoryClear();
    inventoryCopy(ref.memory);
    return *this;
}

MateriaSource::~MateriaSource()
{
    inventoryClear();
}

void MateriaSource::learnMateria(AMateria *m)
{
    int idx;

    if (!m)
        return ;
    for (idx = 0; idx < 4; idx++)
    {
        if (letter[idx] == "")
        {
            memory[idx] = m;
            if (m->getType() == "ice")
                letter[idx] = "ice";
            else if (m->getType() == "cure")
                letter[idx] = "cure";
            return ;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int idx;

    for (idx = 3; idx > -1; idx--)
    {
        if (memory[idx] && type == memory[idx]->getType())
            return memory[idx]->clone();
    }
    return NULL;
}

void MateriaSource::inventorySet()
{
    for (int i = 0; i < 4; i++)
    {
        letter[i] = "";
        memory[i] = NULL;    
    }
}

void MateriaSource::inventoryClear()
{

    for (int i = 0; i < 4; i++)
    {
        if (memory[i])
            delete memory[i];
    }
    inventorySet();
}

void MateriaSource::inventoryCopy(AMateria* const *src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src[i])
        {
            memory[i] = src[i]->clone();
            if (src[i]->getType() == "ice")
                letter[i] = "ice";
            else if(src[i]->getType() == "cure")
                letter[i] = "cure";
        }
    }
}
