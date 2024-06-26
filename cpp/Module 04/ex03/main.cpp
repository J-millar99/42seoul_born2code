#include "MainHeader.hpp"

void f()
{
    system("leaks a.out");
}

int main()
{
    atexit(f);

    std::cout << "-----Subject Case-----" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    // //  -----Learn Materia-----
    // IMateriaSource *src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // src->learnMateria(new Ice()); // Max: handle memory in function(learnMateria)
    // //  -----Create Equip Unequip-----
    // Character *me = new Character("me");
    // Character *some = new Character("some");
    // AMateria *tmp;

    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = NULL;
    // some->equip(tmp);
    // // tmp = src->createMateria("cure");
    // // me->equip(tmp); 
    // // leaks: delete or another Character instance -> equip
    // me->use(0, *me);
    // me->use(0, *me);
    // me->use(1, *me);
    // me->use(1, *me);
    // me->use(2, *me);
    // me->use(2, *me);
    // me->use(3, *me);
    // me->use(3, *me);
    // tmp = me->unequipPtr(0);
    // me->unequip(0);
    // delete tmp;
    // //leaks: delete or another Character instance -> equip
    // tmp = me->unequipPtr(1);
    // me->unequip(1);
    // delete tmp;
    // tmp = me->unequipPtr(2);
    // me->unequip(2);
    // delete tmp;
    // tmp = me->unequipPtr(3);
    // me->unequip(3);
    // delete tmp;
    // me->use(0, *me);
    // me->use(1, *me);
    // me->use(2, *me);
    // me->use(3, *me);
    // delete me;
    // delete src;
    // delete some;
    // return 0;


    // IMateriaSource *src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // Character *me = new Character("me");
    // AMateria *tmp;
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);

    // Character some;
    // some = *me;
    // delete me;
    // some.use(0, some);
    // some.use(1, some);
    // some.use(2, some);
    // some.use(3, some);
    // tmp = some.unequipPtr(0);
    // some.unequip(0);
    // delete tmp;
    // //leaks: delete or another Character instance -> equip
    // tmp = some.unequipPtr(1);
    // some.unequip(1);
    // delete tmp;
    // tmp = some.unequipPtr(2);
    // some.unequip(2);
    // delete tmp;
    // tmp = some.unequipPtr(3);
    // some.unequip(3);
    // delete tmp;
    // some.use(0, some);
    // some.use(1, some);
    // some.use(2, some);
    // some.use(3, some);

    // delete src;
    return 0;
}