#include "MutantStack.hpp"
#include <vector>
#include <list>

template <typename Iterator>
void funcPrintTestCase(Iterator it, Iterator ite)
{
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);                             // stack = {5}
    mstack.push(17);                            // stack = {5, 17}
    std::cout << "top : " << mstack.top() << std::endl;     // top : 17
    mstack.pop();                               // pop : 17
    std::cout << "size : " << mstack.size() << std::endl;    // size : 1
    mstack.push(3);                             // stack = {5, 3}
    mstack.push(5);                             // stack = {5, 3, 5}
    mstack.push(737);                           // stack = {5, 3, 5, 737}
    mstack.push(0);                             // stack = {5, 3, 5, 737, 0}
    std::cout << "forward: ";
    funcPrintTestCase(mstack.begin(), mstack.end());
    std::cout << "reverse: ";
    funcPrintTestCase(mstack.rbegin(), mstack.rend());
    
    std::vector<int> vector(mstack.begin(), mstack.end());
    funcPrintTestCase(vector.begin(), vector.end());
    std::list<int> list(mstack.begin(), mstack.end());
    funcPrintTestCase(list.begin(), list.end());

    std::stack<int> s(mstack);
    return 0;
}
