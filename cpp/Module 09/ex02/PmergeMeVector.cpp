#include "PmergeMe.hpp"

void PmergeMe::mergeInsertSortVector(std::vector<int> &vector, int start, int end)
{
    int newEnd;
    if (start < end)
    {
        if ((end - start) < 10)
            insertSortVector(vector, start, end);
        else
        {
            newEnd = start + (end - start) / 2;
            mergeInsertSortVector(vector,  start, newEnd);
            mergeInsertSortVector(vector, newEnd + 1, end);
            mergeSortVector(vector, start, newEnd, end);
        }
    }
}

void PmergeMe::mergeSortVector(std::vector<int> &vector, int start, int mid, int end)
{
    int i, j, k;

    std::vector<int> left(mid - start + 1);
    std::vector<int> right(end - mid);

    for(i = 0; i < (mid - start + 1); ++i)
        left[i] = vector[start + i];
    for(j = 0; j < (end - mid); ++j)
        right[j] = vector[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            vector[k++] = left[i++];
        else
            vector[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        vector[k++] =  left[i++];
    while (j < (end - mid))
        vector[k++] = right[j++];
}

void PmergeMe::insertSortVector(std::vector<int> &vector, int start, int end)
{
    for(int index = start + 1; index <= end; index++)
    {
        int hold = vector[index];
        int j = index - 1;
        for(; j >= start && vector[j] > hold; --j)
            vector[j + 1] = vector[j];
        vector[j + 1] = hold;
    }
}