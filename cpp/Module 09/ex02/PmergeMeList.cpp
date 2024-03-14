#include "PmergeMe.hpp"

void PmergeMe::lst_merge(std::list<int> &posLst, std::list<int> &left, std::list<int> &right)
{
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt <= *rightIt)
        {
            posLst.push_back(*leftIt);
            ++leftIt;
        }
        else
        {
            posLst.push_back(*rightIt);
            ++rightIt;
        }
    }
    while (leftIt != left.end())
    {
        posLst.push_back(*leftIt);
        ++leftIt;
    }
    while (rightIt != right.end())
    {
        posLst.push_back(*rightIt);
        ++rightIt;
    }
}

void PmergeMe::lst_mergeSort(std::list<int> &posLst)
{
    if (posLst.size() <= 1)
        return;
    std::list<int> left, right;
    int middle = posLst.size() / 2;
    std::list<int>::iterator it = posLst.begin();
    for (int i = 0; i < middle; ++i)
    {
        left.push_back(*it);
        ++it;
    }
    for (size_t i = middle; i < posLst.size(); ++i)
    {
        right.push_back(*it);
        ++it;
    }
    lst_mergeSort(left);
    lst_mergeSort(right);
    posLst.clear();
    lst_merge(posLst, left, right);
}
