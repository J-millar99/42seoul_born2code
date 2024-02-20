#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    srand(time(NULL));
    int ret = rand() % 3;

    switch (ret)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        return NULL;
    }
}

void identify(Base *p)
{
    A *ptr1 = dynamic_cast<A*>(p);
    B *ptr2 = dynamic_cast<B*>(p);
    C *ptr3 = dynamic_cast<C*>(p);

    std::cout << "Base *p actual type: ";
    if (ptr1)
        std::cout << "A";
    if (ptr2)
        std::cout << "B";
    if (ptr3)
        std::cout << "C";
    std::cout << std::endl;
}

void identify(Base &p)
{
    A aRef;
    B bRef;
    C cRef;

    std::cout << "Base &p actual type: ";
    try
    {
        aRef = dynamic_cast<A&>(p);
        std::cout << "A";
    } 
    catch (const std::bad_cast&){}
    try
    {
        bRef = dynamic_cast<B&>(p);
        std::cout << "B";
    }
    catch (const std::bad_cast&){}
    try
    {
        cRef = dynamic_cast<C&>(p);
        std::cout << "C";
    }
    catch (const std::bad_cast&){}
    std::cout << std::endl;
}

int main()
{
    Base *ptr = generate();
    
    identify(ptr);
    identify(*ptr);
    delete ptr;
}