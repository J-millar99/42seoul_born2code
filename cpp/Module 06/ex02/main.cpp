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

    std::cout << "Base *p actual type> ";
    if (ptr1)
        std::cout << "A: " << ptr1;
    if (ptr2)
        std::cout << "B: " << ptr2;
    if (ptr3)
        std::cout << "C: " << ptr3;
    std::cout << std::endl;
}

void identify(Base &p)
{
    std::cout << "Base &p actual type> ";
    try
    {
        A &aRef = dynamic_cast<A&>(p);
        std::cout << "A: " << &aRef;
    } 
    catch (const std::bad_cast&){}
    try
    {
        B &bRef = dynamic_cast<B&>(p);
        std::cout << "B: " << &bRef;
    }
    catch (const std::bad_cast&){}
    try
    {
        C &cRef = dynamic_cast<C&>(p);
        std::cout << "C: " << &cRef;
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