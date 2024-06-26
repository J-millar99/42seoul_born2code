#include "PmergeMe.hpp"

std::list<int>::iterator PmergeMe::lst_binarySearch(std::list<int> &_lst, int key)
{
    std::list<int>::iterator it = _lst.begin();
    while (it != _lst.end() && *it < key) {
        ++it;
    }
    return it;
}

std::list<int> PmergeMe::lst_mergeInsertionSort(std::list<int> &X)
{
    if (X.size() <= 1)
        return X;
    std::list<int> S;
    std::list<int>::iterator it = X.begin();
    while (it != X.end())
    {
        int first = *it;
        ++it;
        if (it == X.end())
        {
            S.push_back(first);
            break;
        }
        int second = *it;
        ++it;
        if (first > second)
        {
            S.push_back(first);
            first = second;
        }
        else
            S.push_back(second);
    }
    S = lst_mergeInsertionSort(S);
    for (std::list<int>::iterator it = X.begin(); it != X.end();)
    {
        if (*it == S.front())
            it = X.erase(it);
        else
            ++it;
    }
    for (std::list<int>::iterator it = X.begin(); it != X.end(); ++it)
    {
        std::list<int>::iterator insert_pos = lst_binarySearch(S, *it);
        S.insert(insert_pos, *it);
    }
    return S;
}
