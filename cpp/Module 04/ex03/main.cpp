#include <iostream>

class A
{
    public:
        void func() {std::cout << "hi" << std::endl; }
};

void f(A **ptr)
{
    for (int i = 0; i < 3; i++)
        std::cout << ptr[i] << std::endl;
}

int main()
{
    A *arr[3];

    for (int i = 0; i < 3; i++)
    {
        A *a = new A();
        arr[i] = a;
    }
    f(arr);
    for (int j = 0; j < 3; j++)
    {
        delete arr[j];
        arr[j] = NULL;
    }
    f(arr);
}