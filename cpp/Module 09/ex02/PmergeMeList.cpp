#include "PmergeMe.hpp"

void PmergeMe::mergeInsertSortList(std::list<int>::iterator start, std::list<int>::iterator end)
{
    std::list<int>::iterator newEnd;

    if (start != end)
    {
        if (std::distance(start, end) < 42)
            insertSortList(start, end);
        else
        {
            newEnd = start;
            std::advance(newEnd, std::distance(start, end) / 2);
            mergeInsertSortList(start, newEnd);
            mergeInsertSortList(++newEnd, end);
            mergeSortList(start, newEnd, end);
        }
    }
}

void PmergeMe::mergeSortList(std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end)
{
    std::list<int> left(start, mid);
    std::list<int> right(++mid, end);
    std::list<int>::iterator leftIter = left.begin();
    std::list<int>::iterator rightIter = right.begin();
    std::list<int>::iterator listIter = start;

    while (leftIter != left.end() && rightIter != right.end())
    {
        if (*leftIter <= *rightIter)
        {
            *listIter = *leftIter;
            ++leftIter;
        }
        else
        {
            *listIter = *rightIter;
            ++rightIter;
        }
        ++listIter;
    }

    while (leftIter != left.end())
    {
        *listIter = *leftIter;
        ++leftIter;
        ++listIter;
    }
    while (rightIter != right.end())
    {
        *listIter = *rightIter;
        ++rightIter;
        ++listIter;
    }
}

void PmergeMe::insertSortList(std::list<int>::iterator start, std::list<int>::iterator end)
{
    for (std::list<int>::iterator index = start; index != end; ++index)
    {
        int hold = *index;
        std::list<int>::iterator j = index;
        --j;
        while (j != start && *j > hold)
        {
            *std::next(j) = *j;
            --j;
        }
        if (*j > hold)
        {
            *std::next(j) = *j;
            *j = hold;
        }
        else
            *std::next(j) = hold;
    }
}
