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

    for (idx = 0; idx < 4; idx++)
    {
        if (letter[idx] == "")
        {
            if (m->getType() == "ice")
            {
                memory[idx] = new Ice(*m);
                letter[idx] = "ice";
            }
            else if (m->getType() == "cure")
            {
                memory[idx] = new Cure(*m);
                letter[idx] = "cure";
            }
            break ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int idx;

    for (idx = 3; idx > -1; idx--)
    {
        if (letter[idx] != "")
        {
            if (type == letter[idx])
                return memory[idx];
        }
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
            if (src[i]->getType() == "ice")
            {
                memory[i] = new Ice(*src[i]);
                letter[i] = "ice";
            }
            else if(src[i]->getType() == "cure")
            {
                memory[i] = new Cure(*src[i]);
                letter[i] = "cure";
            }
        }
    }
}
