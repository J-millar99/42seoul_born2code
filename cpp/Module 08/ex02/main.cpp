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
    std::cout << mstack.top() << std::endl;     // top : 17
    mstack.pop();                               // pop : 17
    std::cout << mstack.size() << std::endl;    // size : 1
    mstack.push(3);                             // stack = {5, 17, 3}
    mstack.push(5);                             // stack = {5, 17, 3, 5}
    mstack.push(737);                           // stack = {5, 17, 3, 5, 737}
    mstack.push(0);                             // stack = {5, 17, 3, 5, 0}

    MutantStack<int>::iterator it = mstack.begin(); // begin : 5
    MutantStack<int>::iterator ite = mstack.end();  // end : 0
    funcPrintTestCase(it, ite);
    std::vector<int> vector(mstack.begin(), mstack.end());
    funcPrintTestCase(vector.begin(), vector.end());
    std::list<int> list(mstack.begin(), mstack.end());
    funcPrintTestCase(list.begin(), list.end());

    std::stack<int> s(mstack);
    return 0;
}